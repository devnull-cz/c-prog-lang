/*
 * Print a decimal number in argv[1] in binary.  Limit the input to a positive
 * int.
 *
 *	$ ./a.out 2147483647
 *	1111111111111111111111111111111
 *	$ ./a.out 255
 *	11111111
 *	$ ./a.out 348508345
 *	10100110001011101000010111001
 *
 * Use bc(1) with obase=2 to verify the output.
 */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int
main(int argc, char **argv)
{
	assert(argc == 2);

	char a[sizeof (int) * 8];
	int i = 1, n = atoi(argv[1]);

	assert(n >= 0);
	(void) memset(a, '0', sizeof (a));
	a[sizeof (a) - 1] = '\0';

	while (n > 0) {
		if (n % 2 == 1)
			a[sizeof (a) - i - 1] = '1';
		if ((n = n / 2) > 0)
			++i;
	}
	printf("%s\n", a + sizeof (a) - i - 1);

	return (0);
}
