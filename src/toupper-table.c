/*
 * We assume C locale.
 */
#include <stdio.h>

int
mytoupper(int c, char table[])
{
	if (c >= 'a' && c <= 'z')
		return (table[c - 'a']);
	return (c);
}

int
main(void)
{
	int c;
	char table['z' - 'a' + 1];

	size_t i = 0;
	c = 'a';
	while (i < sizeof (table) / sizeof (table[0])) {
		table[i] = c - ('a' - 'A');
#ifdef DEBUG
		printf("%c -> %c\n", c, table[i]);
#endif
		i++;
		c++;
	}

	while ((c = getchar()) != EOF)
		printf("%c", mytoupper(c, table));
}
