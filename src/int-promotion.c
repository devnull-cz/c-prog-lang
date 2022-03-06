#include <stdio.h>

int
main(void)
{
	unsigned char a = 0xff;
	/*
	 * This will probably wrap around and is implementation defined by the
	 * spec.
	 */
	signed char b = 0xff;

	int c = (a == b); // true, or false ?

	/*
	 * Note that 'a' and 'b' are first promoted to ints (integer promotion)
	 * when they are being compared.
	 *
	 * Also, %x takes the arguments as UNSIGNED ints.
	 */
	printf("A: %08x, B: %08x\n", a, b);
	printf("C: %d\n", c);

	return (c);
}
