#!/bin/bash

ret=$( find modules/ -type f -name '*.md' | while read f; do
	if ! grep "$f\"" input/*/*.md >/dev/null; then
		echo $f;
	fi;
done; )

if [[ -n $ret ]]; then
	echo "$ret"
	exit 1
fi
