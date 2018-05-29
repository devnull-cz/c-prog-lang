#include <stdio.h>

int
main(void)
{
	int a[] = { 0, 1, 2 };
	int *p = a;

	printf("%d\n", *(p + 2));       // will print 2

	/* Note the increment is by sizeof (int) */
	printf("Size of int: %zu\n", sizeof (int));
	printf("%p\n%p\n%p\n", p, p + 1, p + 2);
}
