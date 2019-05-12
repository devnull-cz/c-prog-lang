#!/bin/bash

cat << INPUT | $ED $INPUTFILE
1h
h
1,1h
h
H
-1h
INPUT

(( $? == 1 )) || exit 1
