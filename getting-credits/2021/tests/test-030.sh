#/bin/bash
#
# Simple test for handling of files (file descriptor leaks).
#

source $configvar
cd $tmpdir
tmp_path=$PWD

name=$(basename $0)

tmp2=tmp-$name
mkdir $tmp2
cd $tmp2
tmp2_path=$PWD

# create bunch of files.
i=0
while (( i < 128 )); do
	cp /etc/passwd "file$i"
	(( i = i + 1 ))
done

# Create the archive.
outfile=$tmp_path/out.tar
output=$($GNUTAR -c -v -f $outfile * 2>&1)
typeset -i ret=$?
((ret == 0)) || { echo "Wrong GNU tar return value $ret." >&2 && exit 1; }
echo "$output" | sed -e "s/^[a-zA-Z0-9/.]*$base: /mytar: /"
cd ..

# Remove the soure files.
rm -rf "$tmp2_path"

# Set the file limit low. 16 should be more than enough for extracting one file.
ulimit -n 16
(($? == 0)) || { echo "Cannot set ulimit: $ret" >&2 && exit 1; }

# Check the ulimit
nfiles=$(ulimit -n)
((nfiles == 16)) || { echo "Unexpected nfiles: $nfiles" >&2 && exit 1; }

# Extract the archive.
mkdir "$name"
cd "$name"
output=$($MYTAR -x -v -f "$outfile" 2>&1)
typeset -i ret=$?
echo "$output" | sed -e "s/^[a-zA-Z0-9/.]*$base: /mytar: /"
((ret == 0)) || { echo "Wrong tar return value $ret." >&2 && exit 1; }

# Check the files.
i=0
while (( i < 128 )); do
	if [[ ! -f "file$i" ]]; then
		echo "File file$i missing"
		exit 1
	fi
	(( i = i + 1 ))
done

# cleanup
cd ..
rm -rf "$name"

exit 0
