#!/bin/bash

echo '-1,1p' | $ED $INPUTFILE

(( $? == 1 )) || exit 1
