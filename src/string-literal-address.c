#include <stdio.h>

int
main(void)
{
	char *s;

	printf("%p\n", s = "hello world");
	printf("%s\n", s);
	/*
	 * This probably prints the same address as the first printf() as only
	 * one copy of the string is usually stored (usually in a read-only
	 * segment).
	 */
	printf("%p\n", "hello world");
}
