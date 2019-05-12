#!/bin/bash

echo '1,$p' | $ED $INPUTFILE

(( $? == 0 )) || exit 1
