#!/bin/bash
#
# Generate HTML pages from Markdown files in the lecture notes branch.
#
# Assumes:
#   - set of Markdown files created in /tmp/notes/<year>/ by expand.sh
#   - master branch checkout with the docs/index.html file
#   - functional (non-expired) personal access token set as the GRIP_PASSWORD variable for Github Actions
#

set -e
set -x

cd gh-pages

if [[ -z $GRIP_PASSWORD ]]; then
	echo "Need non-empty 'GRIP_PASSWORD' environment variable"
	exit 1
fi

# Convert Markdown to HTML.
year=$( ls -1 /tmp/notes | sort -n | tail -1 )
cd /tmp/notes/$year
for mdfile in *.md; do
	grip --pass "$GRIP_PASSWORD" --export "$mdfile"
done

# Construct index page for the notes.
notes="notes.html"
echo "<html><body>" > $notes
echo "<head>Notes for C programming class</head>" >> $notes
echo "<ul>" >> $notes
for htmlfile in [0-9]*.html; do
	echo "<a href=$htmlfile>`basename $htmlfile`</a>" >> $notes
done
echo "</ul>" >> $notes
echo "</body></html>" >> $notes
cd -

# copy documents.
cp ../master/docs/*.html .

mv /tmp/notes/$year/*.html .
git add -f *.html
if [[ -n $( git status -s . ) ]]; then
	git commit -m "Refresh HTML pages"
	git push
fi
