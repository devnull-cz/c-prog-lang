#/usr/bin/env bash
#
# Listing test with specific file arguments.  Use different ordering in argv
# from the ordering in the archive.  However, the files should still be listed
# in the ordering of the archive.

source $configvar
cd $tmpdir

typeset -i last=${#inputfiles[@]}

$MYTAR -t -f "$tarfile" \
    ${inputfiles[6]} ${inputfiles[$last - 1]} ${inputfiles[2]} ${inputfiles[0]}
(($? == 0)) || exit 1
