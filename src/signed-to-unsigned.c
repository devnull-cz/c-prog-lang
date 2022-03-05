/*
 * Be very careful when working with signed and unsigned numbers together.
 * And better do not mix those at all!
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
	 * (2) assigning a value to an unsigned that does not fit causes a wrap
	 *     around by 2^32 (in this case) until the value fits in
	 * (3) So here, it is (-128 + 2^32) = 4294967168.
	 */
	printf("%u\n", i);
}
