#!/bin/bash

echo '1,2p' | $ED $INPUTFILE

(( $? == 0 )) || exit 1
