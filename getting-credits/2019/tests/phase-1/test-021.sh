#!/bin/bash

# verify q does not change the current line

cat << "INPUT" | $ED $INPUTFILE
H
1,10000Y
INPUT

(( $? == 1 )) || exit 1
