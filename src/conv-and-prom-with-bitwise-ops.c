#include <stdio.h>

int
main(void)
{
	/* -1 is promoted to an unsigned int first. */
	printf("%u\n", 13U & -1);
}
