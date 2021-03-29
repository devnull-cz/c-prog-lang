#/bin/bash
#
# One zero block missing triggers a warning but exit is still 0.  Do not check
# the file content here.

source $configvar
cd $tmpdir

tmp2=tmp-$(basename $0)
mkdir $tmp2 || { echo "mkdir failed" && exit 1; }
cd $tmp2

output=$($MYTAR -x -f ../$onezeroblockmissing 2>&1)
typeset -i ret=$?
((ret == 0)) || { echo "Wrong tar return value $ret." >&2 && exit 1; }
echo "$output" | sed -e "s/^[a-zA-Z0-9/.]*$base: /mytar: /"
