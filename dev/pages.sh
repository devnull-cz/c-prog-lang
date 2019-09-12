#!/bin/bash

set -e
set -x

if [[ -z $GH_PAGES_TOKEN ]]; then
	echo "GH_PAGES_TOKEN environment variable is missing"
	exit 1
fi

git config --global user.email "vlada@devnull.cz"
git config --global user.name "vladak"

# The workflow clones the repository (in detached HEAD state) however
# with different method. This makes it easy to just push at the end.
repo_name=repo
git clone --quiet \
    https://${GH_PAGES_TOKEN}@github.com/devnull-cz/c-prog-lang $repo_name

lecture_dir=lecture-notes
for year in `ls -1 $lecture_dir`; do
	if [[ ! -d $lecture_dir/$year ]]; then
		continue
	fi

	echo "Processing year $year"
	cp $lecture_dir/$year/*.md $repo_name/$lecture_dir/$year/
	cd $repo_name
	git add -f $lecture_dir/$year/*.md
	cd -
done

if [[ -n $( git status -s $lecture_dir ) ]]; then
	cd $repo_name
	git commit -m "Latest update of lecture notes"
	git push -fq origin master
	echo "Published latest lecture notes."
else
	echo "Nothing to publish"
fi
