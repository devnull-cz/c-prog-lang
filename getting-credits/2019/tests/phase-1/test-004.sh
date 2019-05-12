#!/bin/bash

echo '1,100p' | $ED $INPUTFILE

(( $? == 1 )) || exit 1
