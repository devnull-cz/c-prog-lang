#!/bin/bash

echo '.,.' | $ED $INPUTFILE

(( $? == 0 )) || exit 1
