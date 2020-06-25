#!/bin/bash

set -e

export STEF="$GITHUB_WORKSPACE/stef/stef.sh"

export GNUTAR=/bin/tar
export MYGNUTAR=$GNUTAR

cd getting-credits/2020/tests
./run-tests.sh
