#include <stdio.h>

int
mytoupper(int c)
{
    if (c >= 'a' && c <= 'z')
        return (c - ('a' - 'A'));
    else
        return c;
}

int
mytoupper_ternary(int c)
{
	return (c >= 'a' && c <= 'z' ? c - ('a' - 'A') : c);
}

int
main(void)
{
	int c;

	while ((c = getchar()) != EOF)
		printf("%c", mytoupper(c));

	return (0);
}
