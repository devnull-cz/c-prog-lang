#include <stdio.h>

int
main(void)
{
	int i = 1, j = 0;

	/*
	 * Demonstrate both operator precedence (i+++j) and modification of
	 * variable (j) between sequencing points.
	 */
	if (((i+++j) > 1) || (++j)) {
		printf("yep\n");
	}

	printf("j = %d\n", j);
}
