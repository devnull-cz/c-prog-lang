#include <stdio.h>

int
main(void)
{
	/* See printf(3) for more information. */
	printf("%5s\n", "foo");
	printf("%5s\n", "foobar");
	printf("%.5s\n", "foo");
	printf("%.5s\n", "foobar");

	/*
	 * We can also align a string to the left, print it with a greater
	 * width, and not print all of it.  We will get the following:
	 *
	 *      :hello, wor     :
	 */
	(void) printf(":%-15.10s:\n", "hello, world");
}
