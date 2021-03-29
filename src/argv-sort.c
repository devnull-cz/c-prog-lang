/*
 * Sort program arguments and print them to standard output.
 *
 * simple test: ./a.out foo bar
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
compare(const void *s1, const void *s2)
{
	return (strcmp(*(char **)s1, *(char **)s2));
}

int
main(int argc, char *argv[])
{
	/* size of argv[0] is a size of (char *) */
	qsort(argv, argc, sizeof (argv[0]), compare);

	do {
		printf("%s\n", *argv);
	} while (*++argv != NULL);
}
