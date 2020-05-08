#!/bin/bash
#
# Create an archive from created files.
#
# Do not put duplicates to the archive as those have typeflag 49 (hardlink) and
# that would be outside of the C class.

typeset srcfile=$MYTARNAME.c

# If MYGNUTAR is set, it is set to MYTAR in stef-config.  It is only for
# verifying the test suite environment is set properly as all tests must pass
# then.
if [[ -z $MYGNUTAR ]]; then
	echo "Checking '$srcfile' existence."
	if [[ $(basename $MYTAR_C) != $srcfile ]]; then
		echo "The source code filename must be named: '$srcfile'"
		echo "It is: '$(basename $MYTAR_C)'"
		exit 1
	fi

	if [[ -f $MYTAR ]]; then
		echo "Removing old '$MYTAR' binary."
		rm -f $MYTAR
		if (($? != 0)); then
			echo "Could not remove '$MYTAR'."
			exit 1
		fi
	fi

	# Build the binary that will be used by the test suite.
	echo "Building the '$MYTARNAME' binary ($MYTAR)."
	echo "Source: $MYTAR_C"
	$GCC -Wall -Wextra -o $MYTAR $MYTAR_C
	if (($? != 0)); then
		echo "Could not build $MYTARNAME."
		exit 1
	fi
else
	echo "WARNING: Using '$MYGNUTAR' as the GNU tar testing binary."
	echo "WARNING: This is only for verifying the test setup."
fi

tmpdir=$(mktemp -d dir.XXXXX)
(($? != 0)) && echo "mktemp failed." && exit 1
echo "Created temporary directory '$tmpdir'."

# We want the config in the test root directory.
configvar=$(pwd)/$configvar

cd $tmpdir

mkdir $emptydir
(($? != 0)) && echo "mkdir failed." && exit 1
$GNUTAR -c -f $tarwithdir $emptydir

printf "export tmpdir=$tmpdir\n\n" > $configvar
printf "export tarfile=$tarfile\n\n" >> $configvar

# Do not change aaa-file size, see below.
aaafile=aaa-file
typeset -i aaafileblocks=20
typeset -i aaafilepartialblocks=$(($aaafileblocks / 2))
typeset input="$aaafile	/dev/urandom	512	$aaafileblocks
file1.random	/dev/urandom	512	100
empty.data	/dev/zero	512	0
file.zero	/dev/zero	512	2
hello-world	/dev/urandom	1024	10
small-file	/dev/urandom	512	1
file2.zero	/dev/zero	512	0
file3.zero	/dev/zero	512	0
another-file2	/dev/urandom	512	50"

echo "Creating files:"
echo "$input" | while read fname source bs count; do
	echo "  $fname"
	dd if=$source of=$fname bs=$bs count=$count 2>/dev/null
	if (($? != 0)); then
		echo "ERROR: dd on '$fname'."
		exit 1
	fi
done

inputfiles=$(echo "$input" | awk '{ print $1 }' | LC_ALL=C sort)
printf "export inputfiles=\"$inputfiles\"\n\n" >> $configvar

echo "Creating a GNU tar archive '$tarfile'."
$GNUTAR -c -f $tarfile $inputfiles
(($? != 0)) && echo "$GNUTAR failed." && exit 1

# aaa-file has $aaafileblocks blocks, so put a header and half of aaa-file's
# block into the partial archive.
echo "Creating '$partial' truncated in the middle of an archived file."
dd if=$tarfile of=$partial count=$((aaafilepartialblocks + 1)) >/dev/null 2>&1
(($? != 0)) && echo "dd failed." && exit 1

echo "Creating a truncated file from $aaafile."
aaa1stblocks=$aaafile-1st-blocks
dd if=$aaafile of=$aaa1stblocks count=$aaafilepartialblocks
(($? != 0)) && echo "dd failed." && exit 1
printf "export aaafile=$aaafile\n\n" >> $configvar
printf "export aaa1stblocks=$aaa1stblocks\n\n" >> $configvar

# We assume that aaa-file (see above) is $aaafileblocks block long.
echo "Creating archives with missing ending zero block(s):"
printf "$onezeroblockmissing 1\n$twozeroblocksmissing 0\n" | \
    while read filename n; do
	dd if=$tarfile of=$filename count=$((aaafileblocks + 1)) >/dev/null 2>&1
	(($? != 0)) && echo "dd failed." && exit 1
	dd if=/dev/zero of=$filename seek=$((aaafileblocks + 1)) \
	    count=$n >/dev/null 2>&1
	(($? != 0)) && echo "dd failed with zero blocks." && exit 1
	echo "  $filename"
    done

exit 0
