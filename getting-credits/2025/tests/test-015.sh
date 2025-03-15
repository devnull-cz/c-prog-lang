#/bin/bash
#
# No warnings when building the mytar binary.

# When verifying the testing environment, we need to exit right now.
[[ -n $MYGNUTAR ]] && exit 0

source $configvar
cd $tmpdir

$GCC -Wall -Wextra $MYTAR_C
