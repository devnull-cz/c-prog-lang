#include <stdio.h>

void
change(int **p, int *val)
{
	*p = val;
}

int
main(void)
{
	int i, j;
	int *p = &i;

	printf("%p %p\n", &i, &j);

	printf("%p\n", p);
	change(&p, &j);
	printf("%p\n", p);

	return (0);
}
