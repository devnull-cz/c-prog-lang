#include <stdio.h>

int
main(void)
{
	int i = 5;
	int *p = &i;

	printf("pointer lives at %p\n", &p);
	printf("pointer points to %p\n", p);
	printf("value of the pointed address: %d\n", *p);
}
