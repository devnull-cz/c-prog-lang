#include <stdio.h>

int
main(void)
{
	unsigned char a = 0xff;
	/*
	 * Assigning a value that does not fit into a signed integer is
	 * implementation defined by the spec but it will likely work the same
	 * way as assigning a non-fitting value into an unsigned integer, i.e.
	 * it will wrap around.
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
	printf("c = (a == b): %d\n", c);
}
