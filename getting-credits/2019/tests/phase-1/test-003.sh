#!/bin/bash

echo '5,10p' | $ED $INPUTFILE

(( $? == 0 )) || exit 1
