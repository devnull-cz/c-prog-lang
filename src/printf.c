#include <stdio.h>

int
main(void)
{
	printf("hello, world\n");
	printf("hello, world\n");
	/* Strings are concatenated automatically (in C99, not in C89). */
	printf("hello, world\n"
	    "hello, world\n");
#if 0
	/*
	 * This will return an error as a new line must not be part of a string
	 * literal.
	 */
	printf("hello, world
	    hello world\n");
#endif
}
