#include <stdio.h>
#include <string.h>

int
main(void)
{
	int i = 1, n = 30;

	printf("Ell\tInches\tCentimeters\n");
	while (i <= n) {
		float cm;
		int in;

		if ((i - 1) % 10 == 0) {
			int j = 0;
			while (j++ < 20)
				printf("-");
			printf("\n");
		}

		in = i * 45;
		cm = in * 2.54;
		printf("%d\t%d\t%.2f\n", i, in, cm);
		++i;
	}

	return (0);
}
