#include <stdio.h>

int
main(void)
{
	int a = 5;
	int *pi = &a;
	char *s = "foo";

	/* Generates a warning, assigning a pointer to an incompatible type. */
	s = pi;
	/* No warning (doing this makes no sense though). */
	s = (char *)pi;

	/*
	 * 's' points to a piece of memory where number 5 is stored.  Say what
	 * happens before running the code.
	 *
	 * Then, redirect the output to a file and run 'od -tx1' on that file.
	 * Explain what happened.
	 */
	printf("'%s'\n", s);
}

#if 0
If unsure, think about how the 4 byte integer with a value of 5 is stored in
memory (beware of endianness).

0x0	0x1	0x2	0x3
?	?	?	?
#endif
