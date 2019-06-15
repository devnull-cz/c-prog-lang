#!/bin/bash
#
# Test "w <file>" with non-empty argv1.

cp $INPUTFILE $TMPINPUTFILE || exit 2

cat <<INPUT | $ED $TMPINPUTFILE
9,15d
w $OUTPUTFILE
2d
w
q
INPUT

(( $? == 0 )) || exit 1

cat $OUTPUTFILE
cat $TMPINPUTFILE
rm -f $OUTPUTFILE $TMPINPUTFILE

exit 0
