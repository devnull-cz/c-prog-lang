/*
 * 2d array static initialization.
 */
#include <stdio.h>

#define	MYSIZE	4

int
main(void)
{
	int i, j;
	int a[MYSIZE][MYSIZE] = {
		{  0,  1,  2,  3 },
		{  4,  5,  6,  7 },
		{  8,  9, 10, 11 },
		{ 12, 13, 14, 15 }
	};

	/* Print the array. */
	for (i = 0; i < MYSIZE; ++i)
		for (j = 0; j < MYSIZE; ++j)
			printf("%d ", a[i][j]);

	putchar('\n');
	return (0);
}
