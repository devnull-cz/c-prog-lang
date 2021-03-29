#include <stdio.h>

int
main(void)
{
	struct foo {
		union {
			int a;
			int b;
		} u;
	} foo;

	foo.u.a = 42;
	printf("%d\n", foo.u.b);
}
