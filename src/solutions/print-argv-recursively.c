/*
 * C can do recursion.
 *
 * Use recursion to print the whole argv, each argument on its own line.
 */

#include <stdio.h>

void
myprint(char **argv)
{
	if (*argv == NULL)
		return;

	printf("%s\n", argv[0]);

#if 0
	/*
	 * These are not going to work (properly) as a way to shift the
	 * argument. Think about what the statements do exactly !
	 */
	*argv = *(argv + 1);
	*argv++;
#endif

	myprint(++argv);
}

int
main(int argc, char **argv)
{
	myprint(argv);
}
