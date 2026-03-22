#include <stdio.h>
#include <err.h>
#include <sys/types.h>

#define	ARRAY_LEN(a)	(sizeof (a) / sizeof (a[0]))

int
main(void)
{
	int a[3][2] = { { 1, 44 }, { 1, 0 }, { 2, 33 } };
	size_t min = -1;

	for (size_t i = 0; i < ARRAY_LEN(a); i++) {
		ssize_t sum = 0;
		for (size_t j = 0; j < ARRAY_LEN(a[0]); j++) {
			if (a[i][j] <= 0) {
				sum = -1;
				break;
			}
			sum += a[i][j];
		}
		if (sum > 0) {
			size_t avg = sum / ARRAY_LEN(a[0]);
			if (avg < min)
				min = avg;
		}
	}

	if (min <= 0)
		errx(1, "no eligible lines for computation\n");
	printf("minimum of averages: %zu\n", min);
}
