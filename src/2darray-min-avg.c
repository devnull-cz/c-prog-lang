#include <stdio.h>
#include <err.h>

int
main(void)
{
	int a[3][2] = { { 1, 44 }, { 1, 0 }, { 2, 33 } };
	size_t min = -1;

	for (size_t i = 0; i < sizeof (a) / sizeof (a[0]); i++) {
		ssize_t sum = 0;
		for (size_t j = 0; j < sizeof (a[0]) / sizeof (a[0][0]); j++) {
			if (a[i][j] <= 0) {
				sum = -1;
				break;
			}
			sum += a[i][j];
		}
		if (sum > 0) {
			size_t avg = sum / (sizeof (a[0]) / sizeof (a[0][0]));
			if (avg < min)
				min = avg;
		}
	}

	if (min > 0)
		printf("minimum of averages: %zu\n", min);
	else
		errx(1, "no eligible lines for computation\n");

	return (0);
}
