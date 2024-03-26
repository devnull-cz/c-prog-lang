#/bin/bash
#
# One zero block missing triggers a warning but exit is still 0.

source $configvar
cd $tmpdir

output=$($MYTAR -t -f $onezeroblockmissing 2>&1)
typeset -i ret=$?
((ret == 0)) || { echo "Wrong tar return value $ret." >&2 && exit 1; }
echo "$output" | sed -e "s/^[a-zA-Z0-9/.]*$base: /mytar: /"
