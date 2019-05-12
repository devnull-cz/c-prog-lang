#!/bin/bash

cat << "INPUT" | $ED $INPUTFILE
H
1q
2H
INPUT

(( $? == 1 )) || exit 1
