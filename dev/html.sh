#!/bin/bash
#
# Generate HTML pages from Markdown files in the lecture notes branch.
#
# Assumes:
#   - set of Markdown files created in /tmp/notes/<year>/ by expand.sh
#

set -e
set -x

cd gh-pages

# Convert Markdown to HTML.
year=$( ls -1 /tmp/notes | sort -n | tail -1 )
cd /tmp/notes/$year
for mdfile in *.md; do
	grip --pass "$GH_PAGES_TOKEN" --export "$mdfile"
done

# Construct index page.
echo "<html><body>" > index.html
echo "<head>Notes for C programming class</head>" >> index.html
echo "<ul>" >> index.html
for htmlfile in [0-9]*.html; do
	echo "<a href=$htmlfile>`basename $htmlfile`</a>" >> index.html
done
echo "</ul>" >> index.html
echo "</body></html>" >> index.html
cd -

mv /tmp/notes/$year/*.html .
git add -f *.html
if [[ -n $( git status -s . ) ]]; then
	git commit -m "Refresh HTML pages"
	git push
fi
