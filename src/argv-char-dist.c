#include <stdio.h>
#include <stdlib.h>
#include <err.h>

int
main(int argc, char *argv[])
{
	if (argc != 4)
		errx(1, "usage: %s <char1> <char2> arg", *argv);

	char c1 = **(argv + 1);
	char c2 = **(argv + 2);

	char *p = *(argv + 3);
	char *p1 = NULL, *p2 = NULL;

	while (*p != '\0') {
		if (*p == c1 && p1 == NULL)
			p1 = p;
		if (*p == c2 && p2 == NULL)
			p2 = p;
		p++;
	}

	if (p1 == NULL || p2 == NULL)
		errx(1, "chars not found");

	printf("%zu\n", p2 - p1);

	return (0);
}
