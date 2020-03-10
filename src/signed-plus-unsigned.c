/*
 * Mixing signed and unsigned numbers is dangerous.
 */
#include <stdio.h>

int
main(void)
{
	/* Will print 1 */
	printf("%d\n", -1 > 1U);

	/* Will print 0 as expected but that's because of overflow. */
	printf("%u\n", -1 + 1U);

	/* Will print 2^32-1 (4294967295) - the overflow is more obvious */
	printf("%u\n", -2 + 1U);

	return (0);
}
