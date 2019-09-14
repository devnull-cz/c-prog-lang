#include <stdio.h>

/* Mixing designated array initializer with fixed initializers */
char array[80] = { [0] = 'A', 'X', [3] = 'f', [4] = 'o', [6] = 'o' };

/*
 * You may see a missing '=' but that is only a GNU extension.  Do not use it in
 * your code.
 */
char a2[80] = { [0] 'A', [2] 'B' };

int
main(void)
{
	int i = 0;

	while (i < sizeof (array) / sizeof (array[0])) {
		if (array[i] != 0)
			printf("%c", array[i]);
		else
			printf("_");

		i++;
	}
	printf("\n");

	printf("a2[2]: %c\n", a2[2]);

	return (0);
}
