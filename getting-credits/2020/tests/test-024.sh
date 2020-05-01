#/bin/bash
#
# Extracting truncated archive reports an error.  Check the listing only here.

source $configvar
cd $tmpdir

tmp2=tmp-$(basename $0)
mkdir $tmp2 || { echo "mkdir failed" && exit 1; }
cd $tmp2

output=$($MYTAR -x -f ../$partial 2>&1)
typeset -i ret=$?
((ret == 2)) || { echo "Wrong tar return value $ret." >&2 && exit 1; }
# uniq is because GNU tar prints "gnutar: Unexpected EOF in archive" twice.
echo "$output" | sed -e "s/^[a-zA-Z0-9/.]*$base: /mytar: /" | uniq
