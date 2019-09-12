#!/bin/bash

git config --global user.email "vlada@devnull.cz"
git config --global user.name "vladak"

# This is probably not necessary as the workflow clones the repo
# (however in detached HEAD state)
git clone --quiet \
    https://${GH_PAGES_TOKEN}@github.com/devnull-cz/c-prog-lang repo

cp lecture-notes/2020/*.md repo/lecture-notes/2020/
cd repo
git add -f lecture-notes/2020/*.md
git commit -m "Latest update of lecture notes"
git push -fq origin master

echo "Published latest lecture notes."
