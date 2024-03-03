#include <stdio.h>

int
main(void)
{
	int c, inword = 0, words = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			words = words + inword;
			inword = 0;
			continue;
		}
		inword = 1;
	}

	if (inword == 1)
		++words;

	printf("%d\n", words);
}
