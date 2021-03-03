#!/bin/bash
#
# Add Markdown files expanded by expand.sh into the lecture notes branch.
#
# Assumes:
#   - git user setup done by gitconfig.sh
#   - Markdown files created in /tmp/notes/<year>/ by expand.sh
#

set -e
set -x

cd notes
year=$( ls -1 /tmp/notes | sort -n | tail -1 )
cp /tmp/notes/$year/*.md .
git add -f *.md

if [[ -n $( git status -s . ) ]]; then
	git commit -m "Latest update of lecture notes"
	git push
	echo "Published latest lecture notes."
else
	echo "Nothing to publish"
fi
