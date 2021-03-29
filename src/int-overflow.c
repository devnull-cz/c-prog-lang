/*
 *  compare the assembly of foo() when compiled with -O0 and -O3
 *
 *  E.g. in GCC 5.4.x you will see that bar() has been optimized away.
 *  This is because signed integer overflow is undefined by the standard
 *  so assuming that it will cause wraparound is not valid.
 *
 *  try to compile with -fstrict-overflow -Wstrict-overflow -O2
 *  (should produce a warning)
 */

#include <stdio.h>
#include <stdlib.h>

void
bar(void)
{
	printf("bar!\n");
}

int
foo(unsigned char x)
{
	int value = 2147483600; /* assuming 32 bit int */

	value += x;
	if (value < 2147483600)	// !!! relying on undefined behavior !!!
		bar();

	return (value);
}

int
main(int argc, char **argv)
{
	if (argc == 2)
		foo(atoi(argv[1]));
}
