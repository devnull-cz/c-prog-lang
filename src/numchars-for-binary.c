/*
 * Determine how many chars (not including the terminating zero)
 * will be needed for binary represenation of given positive number.
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
	unsigned int highest_bit = 0;

	while (i > 0) {
		highest_bit++;
		i >>= 1;
	}

	printf("highest bit = %u\n", highest_bit);
}
