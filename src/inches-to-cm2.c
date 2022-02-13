#include <stdio.h>
#include <string.h>

int
main(void)
{
	int i = 1;

	printf("Inches\tCentimeters\n");
	while (i < 10) {
		printf("%d\t%5.2f\n", i, i * 2.54);
#if 0
		/* Try also these. */
		printf("%d\t%f\n", i, i * 2.54);
		printf("%d\t%.2f\n", i, i * 2.54);
#endif
		++i;
	}
}
