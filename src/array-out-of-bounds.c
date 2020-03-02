/*
 * In general, modern compilers will warn you about out-of-bound access if they
 * can compute the index during the compilation.  And that is the case here for
 * both.
 */
#include <stdio.h>

int
main(void)
{
	int a[1024];
	size_t asize = sizeof (a) / sizeof (a[0]);
	size_t extraindex = asize * 4;

	printf("Number of array elements: %zu\n", asize);

	printf("One-off error (using index %zu)... ", asize);
	fflush(stdout);
	a[asize] = 1;
	printf("OK\n");
	printf("Assigning to index %zu... ", extraindex);
	fflush(stdout);
	a[extraindex] = 1;
	printf("OK\n");
}
