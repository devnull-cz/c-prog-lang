#/bin/bash
#
# Simple extra test.  Will only test the extraction created the right files,
# does not diff the contents - that is another unit test.

source $configvar
cd $tmpdir

tmp2=tmp-$(basename $0)
mkdir $tmp2 || { echo "mkdir failed" && exit 1; }
cd $tmp2

$MYTAR -x -f ../$tarfile
LC_ALL=C /bin/ls -1 *
