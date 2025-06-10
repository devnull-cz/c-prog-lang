#/usr/bin/env bash
#
# Extract test with insufficient permissions to write.

source $configvar
cd $tmpdir

typeset -i last=${#inputfiles[@]}

tmp2=noperms-$(basename $0)
mkdir "$tmp2" || { echo "mkdir failed" && exit 1; }
cd "$tmp2"
chmod -w .

$MYTAR -x -f "../$tarfile"
(($? == 2)) || exit 1
