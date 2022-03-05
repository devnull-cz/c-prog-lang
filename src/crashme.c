/*
 * Note that this involves signed overflow which is undefined behavior in the
 * spec.
 *
 * $ ./a.out 2147483648 -1
 * -2147483648 -1
 * Floating point exception: 8
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv)
{
	int a, b;

	assert(argc == 3);

	a = atoi(argv[1]);
	b = atoi(argv[2]);

	printf("%d %d\n", a, b);

	return (b ? a / b : 0);
}
