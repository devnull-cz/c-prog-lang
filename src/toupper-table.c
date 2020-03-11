#include <stdio.h>

int
mytoupper(int c, int table[])
{
	if (c >= 'a' && c <= 'z')
		return table[c - 'a'];
	else
		return c;
}

int
main(void)
{
	int c;
	int table['z' - 'a' + 1];

	int i = 0;
	c = 'a';
	while (i < sizeof (table) / sizeof (table[0])) {
		table[i] = c - ('a' - 'A');
		// printf("%c -> %c\n", c, table[i]);
		i++;
		c++;
	}

	while ((c = getchar()) != EOF)
		printf("%c", mytoupper(c, table));

	return (0);
}
