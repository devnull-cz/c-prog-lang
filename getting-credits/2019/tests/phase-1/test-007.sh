#!/bin/bash

cat << INPUT | $ED $INPUTFILE
100,1p
h
H
100,1p
INPUT

(( $? == 1 )) || exit 1
