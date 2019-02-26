/*
 * See if char is signed or unsigned.
 *
 * Compile with -fsigned-char -fwrapv and then with -funsigned-char and see the
 * difference.
 *
 * Note: signed overflow behavior is undefined. That's why -fwrapv is used in
 * the signed case.
 */

#include <stdio.h>

int
main(void)
{
	char c = (char) 128;

	printf("%d\n", c);

	return (0);
}
