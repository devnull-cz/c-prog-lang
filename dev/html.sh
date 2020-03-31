#!/bin/bash
#
# Generate HTML pages from Markdown files in lecture-notes.
#
# NOTE: This depends on running ./dev/pages.sh.
#

set -e
set -x

YEAR=2020

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
cd $lecture_dir/$YEAR

# Convert Markdown to HTML.
for mdfile in *.md; do
	grip --pass "$GH_PAGES_TOKEN" --export "$mdfile"
done

# Construct index page.
echo "<html><body>" > index.html
echo "<head>Notes from $YEAR</head>" >> index.html
echo "<ul>" >> index.html
for htmlfile in [0-9]*.html; do
	echo "<a href=$htmlfile>`basename $htmlfile`</a>" >> index.html
done
echo "</ul>" >> index.html
echo "</body></html>" >> index.html

# Fix links to /src
SRCLINK="https://github.com/devnull-cz/c-prog-lang/tree/master/src/"
srclink_escaped=$( echo -n $SRCLINK | sed 's/\//\\\//g' )
for htmlfile in [0-9]*.html; do
	sed -i -e "s/\/src\//$srclink_escaped/g" "$htmlfile"
done

mv *.html $repodir/docs
cd $repodir/docs
git add -f *.html
if [[ -n $( git status -s . ) ]]; then
	git commit -m "Refresh HTML pages"
	git push -fq origin master
fi
