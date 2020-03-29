#!/bin/bash

# See this one on what variables to set.
source ./stef-config

[[ -n $STEF ]] || { echo "STEF variable must be set first.  See README." \
    >&2 && exit 1; }
[[ -x $STEF ]] || { echo "STEF variable value '$STEF' not an executable" \
    "script." >&2 && exit 1; }

for v in $REQ_EXECUTABLES; do
	value=$( eval echo \$$v )

	if [[ -z "$value" ]]; then
	    echo "Variable $v must be defined.  Exiting."
	    exit 1
	fi

	if [[ ! -f $value || ! -x $value ]]; then
	    echo "$value not found or not executable.  Exiting."
	    exit 1
	fi
done

$STEF $*
