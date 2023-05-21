/*
 * Determine how many bits of value 1 are in given positive integer.
 */

#include <stdio.h>
#include <stdlib.h>
#include <err.h>

int
main(int argc, char *argv[])
{
	if (argc != 2)
		errx(1, "usage: %s <positive_num>", argv[0]);

	int i = atoi(argv[1]);
	printf("0x%x\n", i);
	unsigned int ones = 0;

	while (i > 0) {
		if (i & 1)
			ones++;
		i >>= 1;
	}

	printf("ones = %u\n", ones);
}
