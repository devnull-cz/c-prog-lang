#/bin/bash
#
# Simple listing test, -v is ignored

source $configvar
# The -tv options with GNU tar prints long file listing which we do not support
# so just emulate the simple listing and exit.
[[ -n $MYGNUTAR ]] && echo "$inputfiles" && exit 0

cd $tmpdir

$MYTAR -t -v -f $tarfile
