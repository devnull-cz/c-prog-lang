#!/bin/bash
#
# Add Markdown files expanded by expand.sh into the lecture notes branch.
#

set -e
set -x

cd notes
cp /tmp/notes/*.md .
git add -f *.md

if [[ -n $( git status -s . ) ]]; then
	cd "$repo_name"
	git commit -m "Latest update of lecture notes"
	git push -fq
	echo "Published latest lecture notes."
else
	echo "Nothing to publish"
fi
