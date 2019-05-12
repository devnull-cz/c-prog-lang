#!/bin/bash

# verify q does not change the current line

cat << "INPUT" | $ED $INPUTFILE
H
5n
-3,-1n
-3,-1n
.
.n
H
-3,-1n
.n
INPUT

(( $? == 1 )) || exit 1
