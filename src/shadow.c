/*
 * Compile with -Wshadow (GCC).  Also see "./shadow-block.c" for more
 * information.
 */

#include <stdio.h>

int c = 3;

int
foo(void)
{
	int c = 4;

	return (++c);
}

int
main(void)
{
	/* Will print 5. */
	printf("%d\n", foo());
}
