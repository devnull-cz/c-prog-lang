/*
 * $ ./a.out <N> <M> <X> <Y>
 *
 * Allocate a 2d array of strings (you will need to allocated each array line
 * individually).  The array's dimension is NxM, each string is initialized with
 * its position in the array, ie. "X, Y".  Use snprintf(3) to print into the
 * strings.  The command will print the [X,Y] element of the allocated array.
 * Examples:
 *
 * $ ./a.out 5 5 1 2
 * 1, 2
 *
 * $ /a.out 1000 1000 999 13
 * 999, 13
 *
 * Assume arguments are correct integers so that you can use atoi(3) function.
 */
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#define	STRLEN	16

int
main(int argc, char **argv)
{
	int n, m;
	char ***p;

	assert(argc == 5);
	n = atoi(argv[1]);
	m = atoi(argv[2]);

	p = malloc(n * sizeof (char **));
	assert(p != NULL);
	for (int i = 0; i < n; ++i) {
		*(p + i) = malloc(m * sizeof (char *));
		assert(*(p + i) != NULL);

		for (int j = 0; j < m; ++j) {
			*(*(p + i) + j) = malloc(STRLEN);
			assert(*(*(p + i) + j) != NULL);
			snprintf(*(*(p + i) + j), STRLEN, "%d, %d", i, j);
		}
	}

	printf("%s\n", p[atoi(argv[3])][atoi(argv[4])]);
}
