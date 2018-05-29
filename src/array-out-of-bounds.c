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

	a[(sizeof (a) / sizeof (a[0])) + 1] = 1;
	printf("+1\n");
	a[(sizeof (a) / sizeof (a[0])) * 4] = 1;
	printf("+%zu", (sizeof (a) / sizeof (a[0])) * 4);

	return (0);
}
