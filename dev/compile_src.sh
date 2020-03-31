#!/bin/bash

set -e

ls -1 src/*.c | grep -vFf src/blacklist.txt | xargs -n 1 \
    cc -c -Werror -Wall -Wextra -std=c99
