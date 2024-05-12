#include <stdio.h>

struct foo_s {
	unsigned int a : 3;
	unsigned int b : 5;
} foo;

int
main(void)
{
	foo.a = 5;  /*   101 */
	foo.b = 16; /* 10000 */

	foo.a = foo.a ^ foo.b;
	unsigned int xor = foo.a ^ foo.b;

	printf("%u vs %u\n", foo.a, xor);
}
