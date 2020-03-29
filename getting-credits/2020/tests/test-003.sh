#/bin/bash
#
# Listing test with specific file arguments.  Follow the same ordering in argv
# as in the archive.

source $configvar
cd $tmpdir

first=$(echo "$inputfiles" | head -1)
third=$(echo "$inputfiles" | head -3 | tail -1)
seventh=$(echo "$inputfiles" | head -7 | tail -1)
last=$(echo "$inputfiles" | tail -1)

$MYTAR -t -f $tarfile $first $third $seventh $last
(($? == 0)) || exit 1
