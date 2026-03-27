#/usr/bin/env bash
#
# The assignment says files up to 2 GiB are supported.  This test case verifies
# the creation/extraction with a 1 GiB file and checks the file contents is
# correctly extracted.
#
# The (debug) output file $dbgoutput is only printed out by STEF if the test
# case fails.  It is deleted by STEF before the script starts.
#

source $configvar

cd $tmpdir
typeset tmp_path=$PWD

typeset tmp2=tmp-$(basename $0)
mkdir $tmp2 || { echo "mkdir '$tmp2' failed" && exit 1; }
cd $tmp2
typeset tmp2_path=$PWD

typeset -i ret

typeset -i count=1048576
typeset big="gig-file"
typeset bigfilepath="$tmp2_path/$big"
dd if=/dev/urandom of=$bigfilepath bs=1024 count=$count >/dev/null 2>&1
((ret == 0)) || { echo "Cannot create big file '$bigfilepath'." >&2 && exit 1; }
echo "Random file '$bigfilepath' created:" >>$dbgoutput
ls -l $bigfilepath >>$dbgoutput

# Create the tarball with GNU tar.
typeset outfile=$tmp2_path/big.tar
typeset output=$($GNUTAR -c -v -f $outfile $big 2>&1)
ret=$?
((ret == 0)) || { echo "Wrong GNU tar return value $ret." >&2 && exit 1; }
# This is the output to compare.  Replace the actual binary name with "mytar".
echo "$output" | sed -e "s/^[a-zA-Z0-9/.]*$base: /mytar: /"
echo "Tarball '$outfile' created:" >>$dbgoutput
ls -l $outfile >>$dbgoutput

typeset hashcmd="openssl md5"
# Remember the file hash before removing the file.
typeset hash1=$($hashcmd $bigfilepath | cut -f2 -d=)
echo "Hash of the input file (using '$hashcmd'): $hash1" >>$dbgoutput

function getsize
{
	ls -l $1 | cut -f5 -d ' '
}

# Remove the file we just used to create the archive.
typeset -i exp_size=$(getsize $bigfilepath)
rm -f $bigfilepath
(($? == 0)) || { echo "Cannot remove big file '$bigfilepath'." >&2 && exit 1; }

# Extract the file from the tarball using $MYTAR.
output=$($MYTAR -x -v -f $outfile 2>&1)
ret=$?
# This is the output to compare.  Replace the actual binary name with "mytar".
echo "$output" | sed -e "s/^[a-zA-Z0-9/.]*$base: /mytar: /"
((ret == 0)) || { echo "Wrong tar return value $ret." >&2 && exit 1; }

# Check size of the extracted file
typeset -i act_size=$(getsize $big)
((exp_size == act_size)) || \
    { echo "File sizes differ in bytes: $exp_size $act_size" >&2 && exit 1; }

hash2=$(openssl md5 $big | cut -f2 -d=)
[[ $hash1 == $hash2 ]] || \
    { printf "Extracted file '$(pwd)/$big' differs from the source.\n" \
        "hash1:$hash\nhash2:$hash2\n" >&2 && exit 1; }
