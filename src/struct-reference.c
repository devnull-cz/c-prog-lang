#include <stdio.h>

struct foo_s {
	int a;
	char b;
};

int
main(void)
{
	struct foo_s foo;
	struct foo_s *p = &foo;

	printf("%p\n", &foo);
	printf("%p\n", &foo.b);
	/* Will print the same address as &foo */
	printf("%p\n", p);
	/* Will print the same address as &foo.b */
	printf("%p\n", &p->b);
}
