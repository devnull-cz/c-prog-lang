#include <stdio.h>

int
main(void)
{
	int n = 13;
	int *p = &n;
	int i = *p;     // i will be 13

	printf("%d\n", i);
}
