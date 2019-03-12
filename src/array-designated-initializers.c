#include <stdio.h>

// mixing designated array initializer with fixed initializers
char array[80] = { [0] = 'A', 'X', [3] = 'f', [4] = 'o', [6] = 'o' };

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

	return (0);
}
