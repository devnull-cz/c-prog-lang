#include <stdlib.h>

static char *
foo(size_t len)
{
	return ((char *)malloc(len));
}

int
main(void)
{
	char *p = malloc(128);

	*p = 'A';
	free(p);
	*p = 'B';

	char *q = foo(16);
	*q = 'X';
	free(q);
	*q = 'Y';

	return (0);
}
