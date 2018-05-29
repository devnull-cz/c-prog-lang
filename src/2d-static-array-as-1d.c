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
	 * "a" is just a pointer so you can re-type it to a different type
	 * of a pointer.
	 */
	p_i = (int *)a;
	for (i = 0; i < MYSIZE * MYSIZE; ++i) {
		printf("%d\n", p_i[i]);
#if 0
		/*
		 * This is wrong, a[i] is a pointer to the i-th line.  Will not
		 * compile.
		 */
		printf("%d\n", a[i]);
#endif
	}

	return (0);
}
