#!/bin/bash

if [[ -z $STEF_UNCONFIGURE ]]; then
	echo "This script may be run only under the STEF framework."
	echo "Exiting."
	exit 1
fi

source $configvar

echo "Removing temporary directory '$tmpdir'."

[[ -z $tmpdir ]] && echo "Internal error: tmpdir empty.  Exiting" && exit 1

rmdir ./$tmpdir/$emptydir
# Temp files unit tests may create.
rm -rf ./$tmpdir/tmp-test-*
rm -f ./$tmpdir/*
rmdir ./$tmpdir
(($? != 0)) && echo "Failed to rmdir '$tmpdir'." && exit 1
exit 0
