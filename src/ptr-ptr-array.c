#include <stdio.h>

void
first(int **p)
{
	printf("%p = ", *p);
	fflush(stdout);
	printf("%d\n", **p);
}

void
second(int **p)
{
	printf("%p = ", *(p + 1));
	fflush(stdout);
	printf("%d\n", *(*p + 1));
	// printf("%d\n", *(*p + 1));
}

int
main(void)
{
	int i = 42, k = 3, j = 7;
	int *a[] = { &i, &j };
	int b[] = { i, j };

	printf("&i = %p\n", &i);
	printf("&j = %p\n", &j);
	printf(" b = %p\n", b);

	int **ppa = a;
	int *pb = b;

	printf("pb = %p [%d]\n", pb, *pb);

	int **ppb = &pb;

	printf("first:\n");
	first(ppa);
	first(ppb);

	printf("second:\n");
	second(ppa);
	second(ppb);

	return (0);
}
