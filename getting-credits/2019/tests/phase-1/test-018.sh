#!/bin/bash

cat << "INPUT" | $ED $INPUTFILE
q
INPUT

(( $? == 0 )) || exit 1
