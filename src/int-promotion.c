#include <stdio.h>

int
main(void)
{
	unsigned char a = 0xff;
	signed char b = 0xff;

	int c = a == b; // true, or false ?

	/*
	 * Note that 'a' and 'b' are first promoted to ints (integer promotion)
	 * when they are being compared.
	 *
	 * Also, %x converts the arguments to UNSIGNED ints before printing
	 * those.
	 */
	printf("A: %08x, B: %08x\n", a, b);
	printf("C: %d\n", c);

	return (c);
}
