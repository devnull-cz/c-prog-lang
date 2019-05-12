#!/bin/bash

cat << "INPUT" | $ED $INPUTFILE
1,$p
1,2p
10p
INPUT

(( $? == 0 )) || exit 1
