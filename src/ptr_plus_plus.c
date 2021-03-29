#include <stdio.h>

int
main(void)
{
	int n = 5;
	int *p = &n;

	printf("%p %d\n", p, *p);
	(*p)++;
	printf("%p %d\n", p, *p);
	*p++;
	printf("%p %d\n", p, *p);
}
