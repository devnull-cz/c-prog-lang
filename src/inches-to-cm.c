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
		 * You can try to replace cm with "i * 2.54" to see what
		 * happens.  I.e.:
		 *
		 *   printf("%d\t%d\n", i, i * 2.54);
		 */
		printf("%d\t%d\n", i, cm);
		++i;
	}
}
