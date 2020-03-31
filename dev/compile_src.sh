#!/bin/bash

set -e

ls -1 src/*.c | grep -vFf src/blacklist.txt | xargs -n 1 \
    cc -c -Werror -Wno-error=unused-but-set-variable \
    -Wno-error=sign-compare -Wno-error=unused-but-set-variable \
    -Wall -Wextra -std=c99
