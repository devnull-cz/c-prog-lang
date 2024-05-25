#/bin/bash
#
# Listing test with specific file arguments.  Follow the same ordering in argv
# as in the archive.
#

source $configvar
cd $tmpdir

typeset -i last=${#inputfiles[@]}

$MYTAR -t -f "$tarfile" \
    ${inputfiles[0]} ${inputfiles[2]} ${inputfiles[6]} ${inputfiles[$last - 1]}
(($? == 0)) || exit 1
