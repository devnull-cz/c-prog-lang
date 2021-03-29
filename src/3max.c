#include <stdio.h>

int
main(void)
{
	int i = 1, j = 2, k = 3;
	int max;

	max = k > ((i > j) ? i : j) ? k : ((i > j) ? i : j);

	printf("max = %d\n", max);
}
