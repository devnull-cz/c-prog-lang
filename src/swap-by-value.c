#include <stdio.h>

/*
 * This function is essentially useless.
 */
void
swap(int a, int b)
{
	int n = a;

	a = b;
	b = n;
}

int
main(void)
{
	int i = 1;
	int j = 2;

	swap(i, j);
	/* Will print 1 2 */
	printf("%d %d\n", i, j);
}
