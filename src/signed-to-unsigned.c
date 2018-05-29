/*
 * Be careful when working with signed and unsigned numbers together.
 */
#include <stdio.h>

int
main(void)
{
	signed char c = -128;
	unsigned int i;

	i = c;

	/*
	 * Will print 4294967168.  The reason is:
	 *
	 * (1) c was promoted to int above ("integral promotion")
	 * (2) in two's complement, -128 as int is (in steps):
	 *
	 *	- two's complement is one's complement + 1
	 *	- negative number is represented as the two's complement of its
	 *	  absolute value
	 *
	 *	Which means:
	 *
	 *	000000000000000000000000010000000	abs 128
	 *	111111111111111111111111101111111	one's complement
	 *	111111111111111111111111110000000	two's complement
	 *
	 * (3) As unsigned, that is 2^32-1-(2^7-1) = 2^32-128 = 4294967168.
	 */
	printf("%u\n", i);

	return (0);
}
