/*
 * Compile and then run in gdb like this:
 *
 *   break foo
 *   r
 *   step
 *   p/x (int [12])*<insert the address printed here>
 */

#include <stdio.h>

void
foo(void)
{
}

int
main(void)
{
	int a[][2][3] = {
	    { {1,2,3}, {4,5,6} },
	    { {8,7,8}, {9,1,9} },
	};

	printf("%p\n", a);
	foo();
}
