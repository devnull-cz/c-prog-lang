#include <stdio.h>

#define	static_assert(p, cnt)	\
	typedef int __assert ## cnt[(p) ? 1 : -1]

static void
foo(void *x)
{
	printf("%p\n", x);
}

int
main(void)
{
	int i = 0xff;

	static_assert(sizeof(void *) >= sizeof i, 1);
	foo((void *) i);
}
