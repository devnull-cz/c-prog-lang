#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
	int i = 42, j = 7;
	int *a[] = { &i, &j };
	int b[] = { i, j };

	if (argc != 2)
		return(1);

	int idx = atoi(argv[1]);

	printf("%p %p\n", &i, &j);
	printf("%p\n", a);
	printf("%p\n", b);

	int *p = a[idx];
	int *q = &b[idx];

	printf("%p %p\n", p, q);
	printf("%d %d\n", *p, *q);
	printf("%ld\n", p - q);

	return (0);
}
