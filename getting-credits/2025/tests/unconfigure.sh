#!/usr/bin/env bash

if [[ -z $STEF_UNCONFIGURE ]]; then
	echo "This script may be run only under the STEF framework."
	echo "Exiting."
	exit 1
fi

source $configvar

echo "Removing temporary directory '$tmpdir'."

[[ -z $tmpdir ]] && echo "Internal error: '\$tmpdir' empty.  Exiting" && exit 1

# Avoiding rm -rf on any top level directory.
rmdir ./$tmpdir/$emptydir
# Temp files unit tests may create.
rm -rf ./$tmpdir/tmp-test-*
rm -f ./$tmpdir/*
rmdir ./$tmpdir

echo "Removing directory $large_dir"
[[ -z $large_dir ]] && \
    { echo "INTERNAL ERROR: large_dir variable empty"; exit 1; }
[[ $large_dir != /* ]] && \
    { echo "INTERNAL ERROR: large_dir not absolute path"; exit 1; }
rm -rf $large_dir

exit 0
