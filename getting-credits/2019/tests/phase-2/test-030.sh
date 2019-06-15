#!/bin/bash
#
# Test "w <file>" with empty argv1.

cat << INPUT | $ED
0i
hi
hello
.
w $OUTPUTFILE
2i
middle line
.
w
q
INPUT

(( $? == 0 )) || exit 1

cat $OUTPUTFILE
rm -f $OUTPUTFILE

exit 0
