#!/bin/bash

dir=/root
# /var/root is for macOS
[ -d $dir ] || dir=/var/root
[ -d $dir ] || exit 1

# We cannot have the output file to diff against as we expect different otput on
# different systems.  STEF could be extended to support that though (e.g. we
# could chose the output file with a specific suffix).
#
# Note that we will accept solution that prints the error to stdout as well but
# let us not complicate things.
output=$( cat << "INPUT" | $ED $dir 2>&1
h
q
INPUT
)

# Get rid of newlines.
output=$( echo $output )

expected_output="$dir: Permission denied Cannot open input file"

(( $? == 0 )) || exit 1
if [[ $output != $expected_output ]]; then
	printf "Expected output:\n$expected_output\n"
	printf "Actual output:\n$output\n"
	exit 1
fi

exit 0
