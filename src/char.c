/*
 * See if char is signed or unsigned.
 *
 * Compile with -fsigned-char and then with -funsigned-char and see the
 * difference.
 */

#include <stdio.h>

int
main(void)
{
	char c = (char) 128;

	printf("%d\n", c);

	return (0);
}
