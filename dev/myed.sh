#!/bin/bash

set -e

export STEF="$GITHUB_WORKSPACE/stef/stef.sh"
export ED=/bin/ed

cd getting-credits/2019/tests
for phase in phase-1 phase-2; do
	cd $phase
	$STEF
	cd -
done
