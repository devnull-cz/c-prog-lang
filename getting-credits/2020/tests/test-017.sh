#/bin/bash
#
# Simple listing test, -v is ignored

# When verifying the testing environment, we need to exit right now.
[[ -n $MYGNUTAR ]] && exit 0

source $configvar
cd $tmpdir

$MYTAR -t -v -f $tarfile
