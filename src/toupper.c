#include <stdio.h>

int
mytoupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	/* No need for else here, it is implicit here. */
	return c;
}

int
main(void)
{
	int c;

	while ((c = getchar()) != EOF)
		printf("%c", mytoupper(c));
}
