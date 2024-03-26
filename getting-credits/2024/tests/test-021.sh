#/bin/bash
#
# Simple extra test, see test-019.sh.  Use the -v option now.

source $configvar
cd $tmpdir

tmp2=tmp-$(basename $0)
mkdir $tmp2 || { echo "mkdir failed" && exit 1; }
cd $tmp2

$MYTAR -x -v -f ../$tarfile
