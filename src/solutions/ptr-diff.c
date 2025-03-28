#include <stdio.h>

int
main(void)
{
	int i = 1;
	int *p = &i;
	int *q = p + 1;

	printf("%p\n", p);
	printf("%p\n", q);
	/*
	 * The different of two pointers is of ptrdiff_t type.  It is defined as
	 * a signed integer.  You do not need to know what is the exact size on
	 * your architecture if you use the 't' printf modifier (remember we use
	 * 'z' modified for sizeof values).
	 */
	printf("%td\n", q - p);
}
