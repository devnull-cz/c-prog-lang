#/usr/bin/env bash
#
# Listing test with specific file arguments.  Follow the same ordering in argv
# as in the archive for the files from the archive.  Put a few non-existent
# files in the argument list.  Those are expected to be printed to stderr after
# all present files were listed.

source $configvar
cd $tmpdir

typeset -i last=${#inputfiles[@]}

base=$(basename $MYTAR)

# The warning messages start with "$argv0: ".  In case $MYTAR is not
# "mytar", fix the output.
output=$($MYTAR -t -f "$tarfile" \
    nonexistent1 ${inputfiles[0]} nonexistent2 \
    ${inputfiles[2]} ${inputfiles[6]} ${inputfiles[$last - 1]} nonexistent3 2>&1)
ret=$?
((ret == 2)) || { echo "Wrong return value $ret." >&2 && exit 1; }
echo "$output" | sed -e "s/^[a-zA-Z0-9/.]*$base: /mytar: /"
exit 0
