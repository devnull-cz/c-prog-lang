#include <stdio.h>
#include <string.h>

int
main(void)
{
	int i = 1, n = 10;

	printf("Inches\tCentimeters\n");
	while (i < n) {
		printf("%d\t%6.2f\n", i, i * 2.54);
#if 0
		printf("%d\t%f\n", i, i * 2.54);
		printf("%d\t%.2f\n", i, i * 2.54);
#endif
		++i;
	}

	return (0);
}
