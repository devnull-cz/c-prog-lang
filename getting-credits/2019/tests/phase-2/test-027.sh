#!/bin/bash
#
# Insert a before the last line.

cp $INPUTFILE $TMPINPUTFILE || exit 2

cat << "INPUT" | $ED $TMPINPUTFILE
$i
hello
.
w
q
INPUT

(( $? == 0 )) || exit 1

cat $TMPINPUTFILE
rm -f $TMPINPUTFILE

exit 0
