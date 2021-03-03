#!/bin/bash
#
# Expand markdown files (particularly includes)
#
# Assumes:
#   - the 'master' branch checkout out in directory 'master'
#

set -e
set -x

cd master
cli=$PWD/dev/expand.js

lecture_dirname=lecture-notes # where the Markdown files are generated
if [[ ! -d $lecture_dirname ]]; then
	mkdir "$lecture_dirname"
fi

# Work with the latest year in the input directory.
year=$( ls -1 input | sort -n | tail -1 )
echo "Expanding files for year $year"
for jsonfile in input/$year/*.json; do
	$cli "$jsonfile"
done

# copy the generated files to temporary area
mkdir -p /tmp/notes/$year
cp $lecture_dirname/*.md /tmp/notes/$year
