/*
 * Determine if given unsigned integer number has alternating bits.
 * For 'unsigned int', that would be either 1431655765 or 2863311530.
 *
 * This is O(n) solution. One can compare against the constants directly
 * to get O(1) solution, however that way one would not get to exercise
 * the bitwise operators :-)
 */

#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>
#include <limits.h>

int
main(int argc, char *argv[])
{
	if (argc != 2)
		errx(1, "usage: %s <positive_num>", argv[0]);

	errno = 0;
 	unsigned long ul = strtoul(argv[1], NULL , 0);
	if (errno != 0)
		err(1, "invalid number");

	if (ul > UINT_MAX)
		errx(1, "too big number");

	unsigned int num = ul;

	printf("0x%x\n", num);
	unsigned int prev = 0;

	for (size_t i = 0; i < sizeof (num) * 8; i++) {
		printf("%zu: %d\n", i, num & 1);

		if (i > 0 && ((num & 1) ^ prev) == 0) {
			printf("no (bit %zu, prev = %u)\n", i, prev);
			return 0;
		}

		prev = num & 1;
		num >>= 1;
	}

	printf("yes\n");
}
