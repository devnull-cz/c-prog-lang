#/bin/bash
#
# Simple listing test, -v is ignored

source $configvar

# The -tv options with GNU tar prints long file listing which we do not support
# so just emulate the simple listing and exit.
if [[ -n $MYGNUTAR ]]; then
	for i in "${inputfiles[@]}"; do
		echo $i
	done
	exit 0
fi

cd $tmpdir

$MYTAR -t -v -f "$tarfile"
