#include <stdio.h>

#define	ASIZE	40

/*
 * Mixing designated array initializer with fixed initializers.  Use common
 * sense as this may get quite hard to read.
 */
char array[ASIZE] = { [0] = 'A', 'X', [3] = 'f', [4] = 'o', [6] = 'o' };

/*
 * You may see a missing '=' in existing C code but that is only a GNU
 * extension.  Do not use it in your code.
 */
char a2[ASIZE] = { [0] 'A', [2] 'B' };

int
main(void)
{
	size_t i = 0;

	/* Print an underscore instead of a NUL byte. */
	while (i < sizeof (array) / sizeof (array[0])) {
		if (array[i] != 0)
			printf("%c", array[i]);
		else
			printf("_");

		i++;
	}
	printf("\n");

	printf("a2[2]: %c\n", a2[2]);
}
