#!/bin/bash
#
# Add Markdown files expanded by expand.sh into the lecture notes branch.
#

set -e
set -x

if [[ -z $GH_PAGES_TOKEN ]]; then
	echo "GH_PAGES_TOKEN environment variable is missing"
	exit 1
fi

git config --global user.email "vlada@devnull.cz"
git config --global user.name "vladak"

#
# The workflow clones the repository (in detached HEAD state) however
# with different method. This makes it easy to just push at the end.
#
src_repo=$GITHUB_WORKSPACE/repo # configured in the Github checkout action
dst_repo=ssh_repo
git clone --quiet \
    https://${GH_PAGES_TOKEN}@github.com/devnull-cz/c-prog-lang "$dst_repo"
cd "$dst_repo"
git checkout notes
lecture_dirname=lecture-notes # where the Markdown files are generated
cp "$src_repo/$lecture_dirname/"*.md .
git add -f *.md

if [[ -n $( git status -s . ) ]]; then
	cd "$repo_name"
	git commit -m "Latest update of lecture notes"
	git push -fq
	echo "Published latest lecture notes."
else
	echo "Nothing to publish"
fi
