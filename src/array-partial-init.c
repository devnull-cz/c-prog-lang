#include <stdio.h>

char array[80] = { [0] = 'A', [2] = 'f', [4] = 'o', [6] = 'o' };

int
main(void)
{
	size_t i;

	for (i = 0; i < sizeof (array) / sizeof (array[0]); i++) {
		if (array[i] != 0)
			printf("%c", array[i]);
		else
			printf("_");
	}
	printf("\n");

	return (0);
}
