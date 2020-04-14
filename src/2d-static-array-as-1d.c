/*
 * Static arrays are stored in memory by lines.
 */
#include <stdio.h>

#define	MYSIZE	4

int
main(void)
{
	int i, j, n;
	int a[MYSIZE][MYSIZE];
	int *p_i;

	/* Initialize the array. */
	for (i = 0, n = 0; i < MYSIZE; ++i)
		for (j = 0; j < MYSIZE; ++j)
			a[i][j] = n++;

	/*
	 * Print the consequtive memory as a one-dimensional array. Note that
	 * "a" is just a pointer so you can re-type it to a different pointer
	 * type.
	 *
	 * We could also do:
	 *
	 *	p_i = &a[0][0];
	 *	p_i = a[0];	// no need for a cast either
	 */
	p_i = (int *)a;		// you need the cast to silence a warning
	for (i = 0; i < MYSIZE * MYSIZE; ++i) {
		printf("%d\n", p_i[i]);
#if 0
		/*
		 * This would be wrong, a[i] is a pointer to the i-th
		 * one-dimensional array.  May not compile.
		 */
		printf("%d\n", a[i]);
#endif
	}
}
