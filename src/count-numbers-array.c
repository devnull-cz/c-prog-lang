/*
 * Count occurences of 0-9 characters in input.  Print out the result.
 *
 * Test with:
 *
 *	$ cat /etc/passwd | ./a.out
 */
#include <stdio.h>
#include <ctype.h>	// isdigit()

int
main(void)
{
	int c;
	size_t i;
	int counts[10] = { 0 };

	while (1) {
		c = getchar();

		if (c == EOF)
			break;

		if (isdigit(c))
			counts[c - '0']++;
	}

	for (i = 0; i < sizeof (counts) / sizeof (counts[0]); i++)
		printf("%zu: %d\n", i, counts[i]);
}
