#!/bin/bash
#
# Generate HTML pages from Markdown files in lecture-notes.
#
# NOTE: This depends on running ./dev/pages.sh.
#

set -e
set -x

year=2020

pip install grip

if [[ -z $GH_PAGES_TOKEN ]]; then
	echo "GH_PAGES_TOKEN environment variable is missing"
	exit 1
fi

git config --global user.email "vlada@devnull.cz"
git config --global user.name "vladak"

lecture_dir=lecture-notes
cd repo
repodir=$PWD
cd $lecture_dir/$year

# Convert Markdown to HTML.
for mdfile in *.md; do
	grip --pass "$GH_PAGES_TOKEN" --export "$mdfile"
done

# Construct index page.
echo "<html><body>" > index.html
echo "<head>Notes from $year</head>" >> index.html
echo "<ul>" >> index.html
for htmlfile in *.html; do
	echo "<a href=01.html>01</a>" >> index.html
done
echo "</ul>" >> index.html
echo "</body></html>" >> index.html

mv *.html $repodir/docs
cd $repodir/docs
git add -f *.html
git commit -m "Refresh HTML pages"
git push -fq origin master
