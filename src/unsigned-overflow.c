#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int
main(void)
{
	unsigned int a = UINT_MAX;

	printf("%u\n", ++a);
}
