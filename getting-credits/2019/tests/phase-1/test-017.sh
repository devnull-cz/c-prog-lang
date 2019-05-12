#!/bin/bash

cat << "INPUT" | $ED $INPUTFILE
H
pY
1pY
$,$pY
INPUT

(( $? == 1 )) || exit 1
