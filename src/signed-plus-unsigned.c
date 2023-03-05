/*
 * Mixing signed and unsigned numbers is dangerous.
 */
#include <stdio.h>

int
main(void)
{
	/* Will print 1 (true). */
	printf("%d\n", -1 > 1U);

	/*
	 * Will print 0 as expected but that's because of the fact that an
	 * unsigned integer wraps around by definition.
	 */
	printf("%u\n", -1 + 1U);

	/*
	 * Will print 2^32-1 (4294967295) - now it is more obvious as it does
	 * not wrap around.
	 */
	printf("%u\n", -2 + 1U);
}
