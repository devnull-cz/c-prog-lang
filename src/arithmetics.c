#include <stdio.h>

int
main(void)
{
	int i;
	/* You can declare and assign (i.e., to initialize the variable). */
	int k = 13;

	i = k;
	k = k + 1;
	printf("k is %d\n", k);

	/* Anywhere you can use a variable, you can use an expression. */
	printf("k multiplied by 100 is %d\n", k * 100);

	/* Will increment by one */
	++k;
	/* Will increment by one as well, we will see the difference later. */
	k++;
	printf("Twice incremented k is %d\n", k);

	/*
	 * If both arguments are integeres, the result is also an integer.  This
	 * will print 9.
	 */
	printf("100 divided by 11 is %d\n", 100 / 11);
}
