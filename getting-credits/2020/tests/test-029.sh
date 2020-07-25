#/bin/bash
#
# The assignment says files up to 2 GiB are supported. Test archive
# creation/extraction with a 1 GiB file and check the file contents as well.
#

source $configvar
cd $tmpdir
tmp_path=$PWD

tmp2=tmp-$(basename $0)
mkdir $tmp2 || { echo "mkdir failed" && exit 1; }
cd $tmp2
tmp2_path=$PWD

typeset -i count=1048576
big_name="gig-file"
bigfile="$tmp2_path/$big_name"
dd if=/dev/urandom of=$bigfile bs=1024 count=$count >/dev/null 2>&1
((ret == 0)) || { echo "Cannot create big file." >&2 && exit 1; }

# create
outfile=$tmp2_path/big.tar
output=$($GNUTAR -c -v -f $outfile * 2>&1)
typeset -i ret=$?
((ret == 0)) || { echo "Wrong GNU tar return value $ret." >&2 && exit 1; }
echo "$output" | sed -e "s/^[a-zA-Z0-9/.]*$base: /mytar: /"

hash1=$(openssl md5 $bigfile | cut -f2 -d=)

# remove the file we used to create the archive
typeset -i exp_size=$(ls -sk $bigfile | cut -f1 -d " ")
rm $bigfile
((ret == 0)) || { echo "Cannot remove big file." >&2 && exit 1; }

# extract
output=$($MYTAR -x -v -f $outfile 2>&1)
typeset -i ret=$?
echo "$output" | sed -e "s/^[a-zA-Z0-9/.]*$base: /mytar: /"
((ret == 0)) || { echo "Wrong tar return value $ret." >&2 && exit 1; }

# check size of the extracted file
typeset -i act_size=$(ls -sk $big_name | cut -f1 -d " ")
((exp_size == act_size)) || \
    { echo "File sizes differ: $exp_size $act_size" >&2 && exit 1; }

hash2=$(openssl md5 $big_name | cut -f2 -d=)
[[ $hash1 == $hash2 ]] || \
    { printf "Extracted file '$(pwd)/$big_name' differs from the source.\n" \
        "hash1:$hash\nhash2:$hash2\n" >&2 && exit 1; }
