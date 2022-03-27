#/bin/bash
#
# Two zero block missing is accepted without any warning.

source $configvar
cd $tmpdir

$MYTAR -t -f $twozeroblocksmissing
((ret == 0)) || { echo "Wrong tar return value $ret." >&2 && exit 1; }
