#/bin/bash
#
# Refuse anything that does not look like a tar archive.

source $configvar
cd $tmpdir

skipping="Skipping to next header"

output=$($MYTAR -t -f $MYTAR 2>&1)
typeset -i ret=$?
((ret == 2)) || { echo "Wrong tar return value $ret." >&2 && exit 1; }
echo "$output" | grep -v "$skipping" | \
    sed -e "s/^[a-zA-Z0-9/.]*$base: /mytar: /"
