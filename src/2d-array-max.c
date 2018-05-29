#include <stdio.h>

int
getmax(int a[], size_t size)
{
	int max = a[0];

	for (int i = 0; i < size; i++) {
		if (a[i] > max)
			max = a[i];
	}

	return (max);
}

int
main(void)
{
	int a[][2] = { {5, 6}, {8, 7}, {9, 10} };

	for (int i = 0; i < sizeof (a) / sizeof (a[0]); i++) {
		printf("%d\n",
		    getmax(a[i], sizeof (a[0]) / sizeof (a[0][0])));
	}

	return (0);
}
