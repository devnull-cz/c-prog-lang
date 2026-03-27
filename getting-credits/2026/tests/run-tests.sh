#!/usr/bin/env bash

[[ -n $MYGNUTAR ]] && export STEF_REGFILE_LOCAL_VARS=" "

[[ -n $STEF ]] || { echo "STEF variable must be set first.  See README." \
    >&2 && exit 1; }
[[ -x $STEF ]] || { echo "STEF variable value '$STEF' not an executable" \
    "script." >&2 && exit 1; }

command -v stdbuf >/dev/null && prefix="stdbuf -o0"
$prefix $STEF ${@}
