#/bin/bash
#
# Listing test with specific file arguments.  Use different ordering in argv
# from the ordering in the archive.  However, the files should still be listed
# in the ordering of the archive.
#
# And, put a few non-existent files in the argument list.  Those are expected to
# be printed to stderr after all present files were listed.

source $configvar
cd $tmpdir

first=$(echo "$inputfiles" | head -1)
third=$(echo "$inputfiles" | head -3 | tail -1)
seventh=$(echo "$inputfiles" | head -7 | tail -1)
last=$(echo "$inputfiles" | tail -1)

base=$(basename $MYTAR)

# The warning messages start with "$argv0: ".  In case $MYTAR is not
# "mytar", fix the output.
output=$($MYTAR -t -f $tarfile nonexistent1 nonexistent2 $third $last \
    $seventh $first nonexistent3 2>&1)
typeset -i ret=$?
((ret == 2)) || { echo "Wrong tar return value $ret." >&2 && exit 1; }
echo "$output" | sed -e "s/^[a-zA-Z0-9/.]*$base: /mytar: /"
exit 0
