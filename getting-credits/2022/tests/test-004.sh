#/bin/bash
#
# Listing test with specific file arguments.  Use different ordering in argv
# from the ordering in the archive.  However, the files should still be listed
# in the ordering of the archive.

source $configvar
cd $tmpdir

first=$(echo "$inputfiles" | head -1)
third=$(echo "$inputfiles" | head -3 | tail -1)
seventh=$(echo "$inputfiles" | head -7 | tail -1)
last=$(echo "$inputfiles" | tail -1)

$MYTAR -t -f $tarfile $seventh $last $third $first
(($? == 0)) || exit 1
