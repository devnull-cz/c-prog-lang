#!/bin/bash

cat << INPUT | $ED $INPUTFILE
1q
h
1,1q
h
H
-1q
INPUT

(( $? == 1 )) || exit 1
