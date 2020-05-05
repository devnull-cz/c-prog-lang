#include <stdio.h>
#include <stdlib.h>
#include <err.h>


extern void binprint(int n);

static int
count_bits(int n)
{
	int count = 0;

	while (n > 0) {
		count += n & 1;
		n >>= 1;
	}

	return (count);
}

static int
diffbits(int a, int b)
{
	binprint(a);
	binprint(b);

	return (count_bits(a ^ b));
}

int
main(int argc, char *argv[])
{
	if (argc != 3)
		errx(1, "usage: %s <num> <num>", argv[0]);

	printf("%d\n", diffbits(atoi(argv[1]), atoi(argv[2])));

	return (0);
}
