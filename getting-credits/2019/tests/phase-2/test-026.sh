#!/bin/bash
#
# Insert a line at the beginning.

cp $INPUTFILE $TMPINPUTFILE || exit 2

cat <<INPUT | $ED $TMPINPUTFILE
1i
hello
.
w
q
INPUT

(( $? == 0 )) || exit 1

cat $TMPINPUTFILE
rm -f $TMPINPUTFILE

exit 0
