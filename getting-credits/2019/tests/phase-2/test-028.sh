#!/bin/bash
#
# Insert multiple lines, several times.

cp $INPUTFILE $TMPINPUTFILE || exit 2

cat << "INPUT" | $ED $TMPINPUTFILE
$i
hi
hello
.
9i
HI
HELLO
.
w
q
INPUT

(( $? == 0 )) || exit 1

cat $TMPINPUTFILE
rm -f $TMPINPUTFILE

exit 0
