#include <stdio.h>

void
myfn(int a[2][2])
{
	/* Silence the unused parameter warning. */
	(void)a;

        return;
}

int
main(void)
{
	/*
	 * You need () as "*p[2]" would be "p is an array of pointers to int" as
	 * [] has higher priority.  More on that later.
	 */
        int (*p)[2] = NULL;
        int (*p2)[3] = NULL;
	/*
	 * As the the array expression is converted to a pointer, the first
	 * dimension is irrelevant.  All other dimensions are not.
	 */
	int a[99][2];
	int a2[2][3];

        myfn(p);	// OK
        myfn(p2);	// will trigger a warning
        myfn(a);	// OK
        myfn(a2);	// will trigger a warning
}
