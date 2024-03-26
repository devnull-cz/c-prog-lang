#/bin/bash
#
# Make sure some specific functions are not used as those are no allowed.
# Hopefully no one is gonna write its own.
#
# getopt - we want students to process the options on their own
# lseek - we want students to use standard IO API only

# When verifying the testing environment, we need to exit right now.
[[ -n $MYGNUTAR ]] && exit 0

grep -e '\<getopt\>' $MYTAR_C
(($? == 1)) || exit 1

grep -e '\<lseek\>' $MYTAR_C
(($? == 1)) || exit 1
