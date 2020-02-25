#include <stdio.h>
#include <ctype.h>

int
main(void)
{
	unsigned char c = 0;
	while (c < 128) {
		if (isprint(c))
			printf("%2x %c   ", c, c);
		if (!isprint(c))
			printf("%2x NP  ", c);

		if (c != 0 && (c + 1) % 8 == 0)
			printf("\n");

		c++;
	}
}
