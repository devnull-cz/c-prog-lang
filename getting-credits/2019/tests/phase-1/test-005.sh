#!/bin/bash

cat <<INPUT | $ED $INPUTFILE
1,10000p
h
INPUT

(( $? == 1 )) || exit 1
