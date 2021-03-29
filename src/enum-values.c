#include <stdio.h>

enum foo {
	FOO = 42,
	X,
	Y = 2,
	Z,
	BAR
};

int
main(void)
{
	printf("%d\n", FOO);
	printf("%d\n", BAR);
}
