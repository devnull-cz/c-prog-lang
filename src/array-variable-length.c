#include <stdio.h>

static size_t
VLA(int n)
{
	int a[n + 1];	// can use expression

	return sizeof(a);
}

int
main(void)
{
	printf("%zu\n", VLA(4));

	return (0);
}
