#!/bin/bash

cat << "INPUT" | $ED $INPUTFILE
1,$n
1,2n
10n
-7,-2n
INPUT

(( $? == 0 )) || exit 1
