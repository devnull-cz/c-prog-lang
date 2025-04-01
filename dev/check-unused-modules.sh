#!/bin/bash

# First, find modules not used directly in the input files.
not_in_input=$( find modules/ -type f -name '*.md' | while read f; do
	f=$(basename $f)
	if ! grep "^#include \"modules\/.*$f\"" input/*/*.md >/dev/null; then
		echo "$f";
	fi;
done; )

# Next, see if these are referenced from any other module.
ret=$( for f in $not_in_input; do
	if ! grep "#module $f" modules/*.md >/dev/null; then
		echo "$f"
	fi
done )

if [[ -n $ret ]]; then
	echo "$ret"
	exit 1
fi
