#/bin/bash
#
# Listing truncated archive reports an error.

source $configvar
cd $tmpdir

output=$($MYTAR -t -f $partial 2>&1)
typeset -i ret=$?
((ret == 2)) || { echo "Wrong tar return value $ret." >&2 && exit 1; }
echo "$output" | sed -e "s/^[a-zA-Z0-9/.]*$base: /mytar: /"
