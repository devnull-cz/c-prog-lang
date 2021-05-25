#include <stdio.h>

int
main(void)
{
	int shift = sizeof (int) * 8 - 4;
	printf("%u\n", (255 << shift) >> shift);
	printf("%u\n", (255U << shift) >> shift);
}
