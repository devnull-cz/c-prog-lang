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
cd repo/$lecture_dir/2020

grip --export *.md
