#include <stdio.h>

int
main(int argc, char *argv[])
{
	char **p = argv;
	do {
		printf("%p %s\n", *p, *p);
	} while (*++p != NULL);

	return (0);
}
