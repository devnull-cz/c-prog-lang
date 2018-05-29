#include <stdio.h>

/*
 * This function is actually useful in contrast to swap-by-value.c.
 */
void
swap(int *a, int *b)
{
	int n = *a;

	*a = *b;
	*b = n;
}

int
main(void)
{
	int i = 1;
	int j = 2;

	swap(&i, &j);
	/* Will print 2 1 */
	printf("%d %d\n", i, j);
}
