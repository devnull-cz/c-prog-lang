#include <stdio.h>

int
main(void)
{
	int i = 5;
	int *p = &(i + 1);

	printf("%d\n", *p);
}
