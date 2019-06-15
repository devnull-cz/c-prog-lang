#!/bin/bash
#
# q warns for a modified not written into buffer.  Two consequtive q's quit
# though and the editor returns 1.

cp $INPUTFILE $TMPINPUTFILE || exit 2

cat <<INPUT | $ED $TMPINPUTFILE
9,15d
q
h
q
q
INPUT

(( $? == 1 )) || exit 1

cat $TMPINPUTFILE
rm -f $TMPINPUTFILE

exit 0
