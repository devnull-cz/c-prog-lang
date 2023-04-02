#/bin/bash
#
# Wrong option.

source $configvar
cd $tmpdir

$MYTAR -Z
(($? == 2)) || exit 1
