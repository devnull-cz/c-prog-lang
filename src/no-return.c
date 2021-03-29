#include <stdio.h>

int
foo(int a)
{
	if (a > 0)
		return (1);

	printf("foo!\n");
}

int
main(void)
{
	foo(0);
}
