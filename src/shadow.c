/*
 * compile with -Wshadow (GCC)
 */

#include <stdio.h>

int c = 3;

int
foo(void)
{
	int c = 4;

	return ++c;
}

int
main(void)
{
	printf("%d\n", foo());

	return (0);
}
