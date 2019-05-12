#!/bin/bash

cat << "INPUT" | $ED $INPUTFILE
H
Y
1Y
$,$Y
INPUT

(( $? == 1 )) || exit 1
