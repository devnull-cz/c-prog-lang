/*
 * Read characters from the standard input and print them out.
 */
#include <stdio.h>

int
main(void)
{
	int c;

	while (1) {
		c = getchar();
		if (c == EOF)
			return (0);
		printf("%c", c);
	}
}
