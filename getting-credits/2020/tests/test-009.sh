#/bin/bash
#
# Check test of non-existing file.

source $configvar
cd $tmpdir

base=$(basename $MYTAR)

# The warning messages start with "$argv0: ".  In case $MYTAR is not
# "mytar", fix the output.
output=$($MYTAR -t -f /totally/nonexistent.tar 2>&1)
typeset -i ret=$?
((ret == 2)) || { echo "Wrong tar return value $ret." >&2 && exit 1; }

echo "$output" | sed -e "s/^[a-zA-Z0-9/.]*$base: /mytar: /"
exit 0
