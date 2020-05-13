#include <stdio.h>

struct foo_s {
	unsigned int a : 3;
} foo;

int
main(void)
{
	foo.a = 7;
	foo.a++;

	/* Will print 0. */
	printf("%u\n", foo.a);
}
