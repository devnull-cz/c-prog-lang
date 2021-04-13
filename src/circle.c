/*
 * Print a circle with a radius of MYRAD.  As you know, the equation for a
 * circle is:
 *
 *	x^2 + y^2 = MYRAD^2
 *
 * You will need a square root then, use <math.h>:
 *
 *	y = sqrt(MYRAD * MYRAD - x * x);
 *
 * You will need "cc -lm warm-up.c" on Linux to link with the math library.  No
 * need to do that on macOS or Solaris.
 *
 * An extension would be to fill it out as well.  This is what this code does.
 */
#include <math.h>
#include <stdio.h>

#define MYRAD	12

int
main(void)
{
	int i, j;
	char a[2 * MYRAD + 1][2 * MYRAD + 1];

	/* You could use memset(3) for this as well. */
	for (i = 0; i < 2 * MYRAD + 1; ++i)
		for (j = 0; j < 2 * MYRAD + 1; ++j)
			a[i][j] = ' ';

	for (i = 0; i < 2 * MYRAD + 1; ++i) {
		int x = i - MYRAD;
		int arg = MYRAD * MYRAD - x * x;
		int y = sqrt(arg);

#if 1
		/* See memset(3) again and use it to replace this for loop. */
		for (int k = MYRAD - y; k <= MYRAD + y; ++k)
			a[k][i] = '*';

#else
		/* The following just prints the circle with no filling. */
		a[MYRAD - y][i] = '*';
		a[MYRAD + y][i] = '*';
#endif
	}

	/* Print out the array. */
	for (i = 0; i < 2 * MYRAD + 1; ++i) {
		for (j = 0; j < 2 * MYRAD + 1; ++j)
			printf("%c", a[i][j]);
		printf("\n");
	}
}
