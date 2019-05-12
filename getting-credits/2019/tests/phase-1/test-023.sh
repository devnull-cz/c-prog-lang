#!/bin/bash

# verify we first report an uknown command before the suffix
cat << "INPUT" | $ED $INPUTFILE
H
1,1Yz
1,1pY
INPUT

(( $? == 1 )) || exit 1
