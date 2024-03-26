#/bin/bash
#
# Directories (actually, headers for non-files) are not supported.

# When verifying the testing environment, we need to exit right now.
[[ -n $MYGNUTAR ]] && cat test-output-007.txt && exit 0

source $configvar
cd $tmpdir

base=$(basename $MYTAR)

# The warning messages start with "$argv0: ".  In case $MYTAR is not
# "mytar", fix the output.
output=$($MYTAR -t -f $tarwithdir 2>&1)
typeset -i ret=$?
((ret == 2)) || { echo "Wrong tar return value $ret." >&2 && exit 1; }

echo "$output" | sed -e "s/^[a-zA-Z0-9/.]*$base: /mytar: /"
exit 0
