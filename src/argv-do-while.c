#include <stdio.h>

int
main(int argc, char *argv[])
{
	do {
		printf("%p '%s'\n", *argv, *argv);
	} while (*++argv != NULL);
}
