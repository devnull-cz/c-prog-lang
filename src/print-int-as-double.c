/*
 * There is no implicit type conversion for variadic function arguments aside
 * from the integeter promotion (which does no apply here).
 */
#include <stdio.h>

int
main(void)
{
	/* Will not print 1.0 */
	printf("%.8f\n", 1);

	/* This is correct and will print 1.0000000 */
	printf("%.8f\n", (double)1);
}
