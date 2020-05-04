#include <stdio.h>

int
main(void)
{
	unsigned char c;
	unsigned int u;

	/* 'c' will be 3.  With -Wconstant-conversion you may get a warning. */
	c = 1027;
	printf("%hhu\n", c);

	/*
	 * Looking for the smallest non-negative integer congruent with -1000
	 * modulo 256.  That is (-1000 + 256 + 256 + 256 + 256 -> -1000 + 1024
	 * -> 24.
	 *
	 * So 24 will be assigned to 'c'.
	 *
	 * The compiler will warn you though as the value changes
	 * (see above for -Wconstant-conversion).
	 */
	c = -1000;
	printf("%hhu\n", c);

	/*
	 * Assuming 'i' is 4 byte in size, the smallest integer congruent with
	 * -10 modulo 2^32 that fits an int is (-10 + 2^32).  Use bc(1):
	 *
	 *	$ bc
	 *	-10+2^32
	 *	4294967286
	 *
	 * So it means 'i' will be assigned 4294967286.
	 */
	u = -10;
	printf("%u\n", u);
}
