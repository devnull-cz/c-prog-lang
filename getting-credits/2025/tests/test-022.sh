#/usr/bin/env bash
#
# Extract test with specific file arguments.  Follow the same ordering in argv
# as in the archive.  Just check the file listing first, do not check the
# contents.

source $configvar
cd $tmpdir

typeset -i last=${#inputfiles[@]}

tmp2=tmp-$(basename $0)
mkdir "$tmp2" || { echo "mkdir failed" && exit 1; }
cd "$tmp2"

$MYTAR -x -v -f "../$tarfile" \
    ${inputfiles[0]} ${inputfiles[2]} ${inputfiles[6]} ${inputfiles[$last - 1]}
(($? == 0)) || exit 1
