#include <stdio.h>

int
main(void)
{
	int i = 1;
	int *p = &i;
	int *q = p + 1;

	printf("%p\n", p);
	printf("%p\n", q);
	printf("%ld\n", q - p);

	return (0);
}
