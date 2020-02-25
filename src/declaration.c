#include <stdio.h>

int
main(void)
{
	/*
	 * int is usually 4 bytes.  It does not have to be but on 32 and 64 bit
	 * CPUs it is 4 bytes.
	 */
	int i;

	/* Assignment */
	i = 0;

	/* % starts a conversion specification.  'd' is for an int (decimal). */
	printf("%d\n", i);

	/* No need to use return, C99 will make sure 0 is returned here. */
}
