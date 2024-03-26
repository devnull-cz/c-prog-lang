#/bin/bash
#
# Listing test with specific file arguments.  Follow the same ordering in argv
# as in the archive for the files from the archive.  Put a few non-existent
# files in the argument list.  Those are expected to be printed to stderr after
# all present files were listed.

source $configvar
cd $tmpdir

first=$(echo "$inputfiles" | head -1)
third=$(echo "$inputfiles" | head -3 | tail -1)
seventh=$(echo "$inputfiles" | head -7 | tail -1)
last=$(echo "$inputfiles" | tail -1)

base=$(basename $MYTAR)

# The warning messages start with "$argv0: ".  In case $MYTAR is not
# "mytar", fix the output.
output=$($MYTAR -t -f $tarfile nonexistent1 $first nonexistent2 \
    $third $seventh $last nonexistent3 2>&1)
ret=$?
((ret == 2)) || { echo "Wrong return value $ret." >&2 && exit 1; }
echo "$output" | sed -e "s/^[a-zA-Z0-9/.]*$base: /mytar: /"
exit 0
