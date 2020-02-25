#!/bin/bash

YEAR=2020

# Expand markdown files (particularly includes)

if [[ -x ./node_modules/markdown-include/bin/cli.js ]]; then
	cli=./node_modules/markdown-include/bin/cli.js
elif [[ -x ~/node_modules/markdown-include/bin/cli.js ]]; then
	cli=~/node_modules/markdown-include/bin/cli.js
else
	echo "Unknown location of cli.js for markdown-include"
	exit 1
fi

for jsonfile in input/$YEAR/*.json; do
	$cli "$jsonfile"
done
