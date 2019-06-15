#!/bin/bash
#
# Verify error message with "w<file>", i.e. a missing space after 'w'.

cat <<INPUT | $ED
wfile
h
q
INPUT

(( $? == 1 )) || exit 1

exit 0
