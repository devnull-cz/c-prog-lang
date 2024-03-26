#/bin/bash
#
# Make sure tar with no options but an argument exits with 2.

$MYTAR anything
(($? == 2)) && exit 0
exit 1
