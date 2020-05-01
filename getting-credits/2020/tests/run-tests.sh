#!/bin/bash

[[ -n $STEF ]] || { echo "STEF variable must be set first.  See README." \
    >&2 && exit 1; }
[[ -x $STEF ]] || { echo "STEF variable value '$STEF' not an executable" \
    "script." >&2 && exit 1; }

$STEF $*
