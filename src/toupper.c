#include <stdio.h>

int
mytoupper(int c)
{
	/*
	 * Note that we assume the C locale.  With other locales, this code may
	 * not be correct.
	 */
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	/* No need for else here, it is implicit. */
	return (c);
}

int
main(void)
{
	int c;

	while ((c = getchar()) != EOF)
		printf("%c", mytoupper(c));
}
