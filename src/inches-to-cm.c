#include <stdio.h>
#include <string.h>

int
main(void)
{
	int i = 1, n = 10;

	printf("Inches\tCentimeters\n");
	while (i < n) {
		int cm;

		cm = i * 2.54;
		printf("%d\t%d\n", i, cm);
		++i;
	}

	return (0);
}
