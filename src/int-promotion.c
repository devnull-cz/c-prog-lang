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
	printf("a: %hhu, b: %hhd\n", a, b);
	printf("a: %08x, b: %08x\n", a, b);
	printf("b: %d\n", c);

	return (c);
}
