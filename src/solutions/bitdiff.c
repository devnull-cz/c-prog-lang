#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <err.h>

/* from print-in-binary.c */
void
binprint(int n)
{
	char a[sizeof (int) * 8];
	int i = 1;

	assert(n >= 0);
	(void) memset(a, '0', sizeof (a));
	a[sizeof (a) - 1] = '\0';

	while (n > 0) {
		if (n % 2 == 1)
			a[sizeof (a) - i - 1] = '1';
		if ((n = n / 2) > 0)
			++i;
	}

	printf("%8s\n", a + sizeof (a) - i - 1);
}

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
}
