#include <stdio.h>

int
main(void)
{
	struct {
		int a;
		char b;
	} foo;

	foo.a = 42;
	printf("%d\n", foo.a);
}
