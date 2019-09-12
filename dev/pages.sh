#!/bin/bash

if [[ -z $GH_PAGES_TOKEN ]]; then
	echo "GH_PAGES_TOKEN environment variable is missing"
	exit 1
fi

git config --global user.email "vlada@devnull.cz"
git config --global user.name "vladak"

# The workflow clones the repo (in detached HEAD state) however
# with different method. This makes it easy to just push at the end.
git clone --quiet \
    https://${GH_PAGES_TOKEN}@github.com/devnull-cz/c-prog-lang repo

for year in `ls -1 lecture-notes`; do
	if [[ ! -d lecture-notes/$year ]]; then
		continue
	fi

	cp lecture-notes/$year/*.md repo/lecture-notes/$year/
	cd repo
	git add -f lecture-notes/$year/*.md
	cd -
done

git commit -m "Latest update of lecture notes"
git push -fq origin master

echo "Published latest lecture notes."
