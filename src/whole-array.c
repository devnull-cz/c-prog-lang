#include <stdio.h>

#define	TOTAL_ELEMENTS (sizeof (array) / sizeof (array[0]))

int array[] = {23, 34, 12, 17, 204, 99, 16};

int
main(void)
{
	int d = -1;

	while (d <= (TOTAL_ELEMENTS - 2)) {
		printf("%d\n", array[d + 1]);
		d++;
	}

	return (0);
}
