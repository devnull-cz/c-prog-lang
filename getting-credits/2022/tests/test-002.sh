#/bin/bash
#
# Simple listing test.

source $configvar
cd $tmpdir

$MYTAR -t -f $tarfile
