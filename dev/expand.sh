#!/bin/bash
#
# Expand markdown files (particularly includes)
#

cli=$PWD/dev/expand.js

cd master

lecture_dirname=lecture-notes # where the Markdown files are generated
if [[ ! -d $lecture_dirname ]]; then
	mkdir "$lecture_dirname"
fi

year=$( ls -1 input | sort -n | tail -1 )
echo "Expanding files for year $year"
for jsonfile in input/$year/*.json; do
	$cli "$jsonfile"
done

# copy the generated files to temporary area
mkdir /tmp/notes
cp $lecture_dirname/*.md /tmp/notes
