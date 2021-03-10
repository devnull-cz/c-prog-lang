#include <stdio.h>

int
main(void)
{
	int x, i = 4;  // not comma operator !

	while (x = 1, printf("foo\n"), i < 6) {
		i += x;
	}

	return (++i, i);	// the parens are there just for style
				// what if you change ++i to i++ ?
				// what if you change this to (x, ++i, i) ?
}
