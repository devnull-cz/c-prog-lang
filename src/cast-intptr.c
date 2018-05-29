/*
 * Try to run this as 64-bit program on both little endian (Intel) and big
 * endian machine (SPARC, MIPS, some ARM chips in some modes) and compare
 * the outputs. What exactly is going on ?
 */

#include <stdio.h>

static void
xor(int *p)
{
	printf("%p\n", p);
	*p ^= 0x11223344;
}

int
main(void)
{
	size_t i = 0xaabbccdd;

	printf("%p\n", &i);
	printf("%x\n", (int) i);
	xor((int *) &i);
	printf("%x\n", (int) i);

	return (0);
}
