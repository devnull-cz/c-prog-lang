#/bin/bash
#
# The tar implementation can extract 8GB+ file.
#

source $configvar

mkdir -p $large_extract_dir || \
    { echo "Could not create $large_extract_dir" >&2; exit 1; }

cd $large_extract_dir
$MYTAR -x -f $large_dir/$large_archive 2>&1
typeset -i ret=$?
((ret == 0)) || { echo "Wrong tar return value $ret." >&2; exit 1; }

typeset original=$large_dir/$largefile
typeset extracted=$large_extract_dir/$largefile
if ! diff -q $extracted $original; then
	echo "Extracted $extracted does not match original $original"
	exit 1
fi
