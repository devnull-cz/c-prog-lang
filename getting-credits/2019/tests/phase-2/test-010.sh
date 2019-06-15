#!/bin/bash
#
# Delete lines multiple times.

cp $INPUTFILE $TMPINPUTFILE || exit 2

cat << "INPUT" | $ED $TMPINPUTFILE
9,15d
1d
$d
$d
w
q
INPUT

(( $? == 0 )) || exit 1

cat $TMPINPUTFILE
rm -f $TMPINPUTFILE

exit 0
