/*
 * Compile with 'gcc -std=c99 -pedantic' to see the warning.
 *
 * Other compilers may just fail.  As this is not allowed by the C99
 * specification, do not use it.
 */
#include <stdio.h>

int
main(void)
{
	int a[0];	// this is forbidden in C99

	a[0] = 1;	// this is undefined behavior

	printf("%zu\n", sizeof (a[0]));	// compiler will not access the array
}
