#!/bin/bash

# verify h does not change the current line

cat << "INPUT" | $ED $INPUTFILE
H
1
5h
.n
INPUT

(( $? == 1 )) || exit 1
