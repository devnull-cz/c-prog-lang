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

base=$(basename $MYTAR)

typeset -i last=${#inputfiles[@]}

# The warning messages start with "$argv0: ".  In case $MYTAR is not
# "mytar", fix the output.
output=$($MYTAR -t -f "$tarfile" \
    nonexistent1 nonexistent2 ${inputfiles[2]} ${inputfiles[$last - 1]} \
    ${inputfiles[6]} ${inputfiles[0]} nonexistent3 2>&1)
typeset -i ret=$?
((ret == 2)) || { echo "Wrong tar return value $ret." >&2 && exit 1; }
echo "$output" | sed -e "s/^[a-zA-Z0-9/.]*$base: /mytar: /"
exit 0
