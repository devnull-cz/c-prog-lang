#!/bin/bash

# Will print the first line, then 4 more as just hitting enter prints the next
# line after the current one.
cat << INPUT | $ED $INPUTFILE
1p




INPUT

(( $? == 0 )) || exit 1
