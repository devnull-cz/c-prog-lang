#!/bin/bash

cat << "INPUT" | $ED $INPUTFILE
1
.,.
INPUT

(( $? == 0 )) || exit 1
