#!/bin/bash
#
# Generate HTML pages from Markdown files in lecture-notes.
#
# NOTE: This depends on running ./dev/pages.sh.
#

set -e
set -x

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
cd $lecture_dir/2020

# Convert Markdown to HTML.
grip --pass "$GH_PAGES_TOKEN" --export *.md

# Construct index page.
echo "<html><body>" > index.html
for htmlfile in *.html; do
	echo "<a href=01.html>01</a>" >> index.html
done
echo "</body></html>" >> index.html

mv *.html $repodir/docs
cd $repodir/docs
git add -f *.html
git commit -m "Refresh HTML pages"
git push -fq origin master
