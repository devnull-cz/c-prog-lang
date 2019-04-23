#include <stdio.h>

int
main(void)
{
	struct foo {
		union {
			int a;
			int b;
		};
	} foo;

	foo.a = 42;
	printf("%d\n", foo.b);

	return (0);
}
