/*
 * compile with -Wshadow (GCC)
 */

#include <stdio.h>

int
foo(void)
{
	int c = 4;

	{
		int c = 1;
		c++;
	}

	return (++c);
}

int
main(void)
{
	printf("%d\n", foo());

	return (0);
}
