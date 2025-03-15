#/bin/bash
#
# Another extract test.  Now check the contents of the files.

source $configvar
cd $tmpdir

tmp2=tmp-$(basename $0)
mkdir $tmp2 || { echo "mkdir failed" && exit 1; }
cd $tmp2

typeset -i belated=0

$MYTAR -x -f ../$tarfile
(($? == 0)) || exit 1

for i in $(/bin/ls -1 *); do
	# We only check files that were extracted.  There is another test that
	# verifies the list of extracted files so missing files here is OK.
	diff -bq $i ../$i || { echo "File $i difference." >&2; belated=1; }
done

((belated != 1)) || exit 1
