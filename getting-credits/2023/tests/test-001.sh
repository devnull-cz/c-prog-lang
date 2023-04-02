#/bin/bash
#
# Make sure tar with no arguments exits with 2.

$MYTAR
(($? == 2)) && exit 0
exit 1
