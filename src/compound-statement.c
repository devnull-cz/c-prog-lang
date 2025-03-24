#include <stdio.h>

int
main(void)
{
	int i = 0;

	{ /* Start of block (compound statement) */
		/* variable declaration with initialization */
		int i = 8;

		/*
		 * expression statement (note that a function call is just an
		 * expression in C).
		 */
		printf("%d\n", i);
	} /* End of block statement, no semicolon needed (but allowed) */

	/*
	 * This 'i' is not related to the 'i' variable used in the block above.
	 */
	++i;

	/* Will return 1 */
	return (i);
}
