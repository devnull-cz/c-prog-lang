#!/bin/bash

# verify q does not change the current line

cat << "INPUT" | $ED $INPUTFILE
H
1
5q
.n
INPUT

(( $? == 1 )) || exit 1
