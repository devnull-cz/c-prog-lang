/*
 * Compile with -Wshadow (GCC) to see the warning about having the variable 'c'
 * shadowing the other one of the same name, but representing different objects.
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
	/* Will print 5. */
	printf("%d\n", foo());
}
