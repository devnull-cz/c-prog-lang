#include <stdio.h>

void
change_ptr(int **p, int *val)
{
	*p = val;
}

int
main(void)
{
	int i, j;
	int *p = &i;

	printf("&i = %p, &j = %p\n", &i, &j);

	printf("p = %p\n", p);
	change_ptr(&p, &j);
	printf("p = %p\n", p);
}
