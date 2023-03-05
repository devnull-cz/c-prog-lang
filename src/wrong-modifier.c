#include <stdio.h>

int
main(void)
{
	/*
	 * This is NOT OK.  Very probably will print some random number if
	 * compiled with "-m 32".  If compiled in 64 bits, it will probably work
	 * fine but the compile should warn you anyway as it is still incorrect
	 * code.
	 */
	printf("%lld\n", 13);

	/* The following is always correct.  Why? */
	char c = 13;
	printf("%d\n", c);
}
