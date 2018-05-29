#include <stdio.h>

int
main(void)
{
	int i = -1;
	unsigned int u = i;

	printf("0x%x\n", i);
	printf("%u\n", u);
	printf("%u\n", (u << 24) >> 24);

	return (i);
}
