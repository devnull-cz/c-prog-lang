#include <stdio.h>

int
mytoupper(int c)
{
	return (c >= 'a' && c <= 'z' ? c - ('a' - 'A') : c);
}

int
main(void)
{
	int c;

	while ((c = getchar()) != EOF)
		printf("%c", mytoupper(c));
}
