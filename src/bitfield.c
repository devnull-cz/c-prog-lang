#include <stdio.h>
#include <stddef.h>

struct foo {
	unsigned short a : 15;
	short b : 2;
};

int
main(void)
{
	printf("%zu\n", sizeof (struct foo));

	int a = 65534;
	int b = -5;
	struct foo foo = { .a = 0, .b = 0 };

	foo.a = a;
	foo.b = b;

	printf("%x -> %x (%d)\n", a, foo.a, foo.a);
	printf("%x -> %x (%d)\n", b, foo.b, foo.b);
}
