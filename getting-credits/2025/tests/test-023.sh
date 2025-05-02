#/usr/bin/env bash
#
# Extract test with specific file arguments.  Follow the same ordering in argv
# as in the archive.  Check the contents now.

source $configvar
cd $tmpdir

typeset -i last=${#inputfiles[@]}

tmp2=tmp-$(basename $0)
mkdir $tmp2 || { echo "mkdir failed" && exit 1; }
cd $tmp2

$MYTAR -x -v -f "../$tarfile" \
    ${inputfiles[0]} ${inputfiles[2]} ${inputfiles[6]} ${inputfiles[$last - 1]}
(($? == 0)) || exit 1

for i in $(/bin/ls -1 *); do
	# We only check files that were extracted.  There is another test that
	# verifies the list of extracted files so missing files here is OK.
	diff -bq $i ../$i || { echo "File $i difference." >&2; belated=1; }
done

((belated != 1)) || exit 1
