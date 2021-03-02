#include <stdio.h>
#include <string.h>

int
main(void)
{
	int i = 1;
	int cm;

	printf("Inches\tCentimeters\n");
	while (i < 10) {
		cm = i * 2.54;
		/*
		 * You can try to place "i * 2.54" instead of cm to see what
		 * happens.
		 */
		printf("%d\t%d\n", i, cm);
		++i;
	}
}
