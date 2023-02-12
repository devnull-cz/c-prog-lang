#include <stdio.h>

int
main(void)
{
	int i = 0;

	while (i < 10) {
		printf("%d\n", i);
		++i;
	}
	printf("--\n");

	/*
	 * No need for {} for a single line body but some people would still
	 * prefer using {}s.
	 */
	i = 0;
	while (i < 10)
		printf("%d\n", i++);
}
