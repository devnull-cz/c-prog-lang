#include <stdio.h>

void
first(int **p)
{
	printf("%p = %d\n", *p, **p);
}

void
second(int **p)
{
	printf("%p -> %d (in hex 0x%x)\n", *(p + 1), **(p + 1), **(p + 1));
}

int
main(void)
{
	int i = 42, j = 7, k = 99;
	int *a[] = { &i, &j, &k };
	int **ppa = a;

	printf(" &i = %p (%d)\n", &i, i);
	printf(" &j = %p (%d)\n", &j, j);
	printf(" &k = %p (%d)\n", &k, k);
	printf("  a = %p\n", a);


	int b[] = { i, j, k };
	int *pb = b;
	int **ppb = &pb;

	printf("  b = %p\n", b);
	printf(" pb = %p [*pb = %d]\n", pb, *pb);
	printf("ppb = %p [*ppb = %p]\n", ppb, *ppb);

	printf("first:\n");
	first(ppa);
	first(ppb);

	printf("second:\n");
	second(ppa);
	second(ppb);
}
