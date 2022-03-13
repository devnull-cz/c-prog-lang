/*
 * Compile and then run in gdb like this:
 *
 *   $ gdb ./a.out
 *   break foo
 *   r
 *   step
 *   p/x (int [12])*<insert the address printf() printed here>
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

	printf("%p\n", (void *)a);
	/* We set the break here to stop the execution before program exits. */
	foo();
}
