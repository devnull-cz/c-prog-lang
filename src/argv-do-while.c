#include <stdio.h>

int
main(int argc, char *argv[])
{
	(void)argc;

	do {
		printf("%p '%s'\n", (void *)*argv, *argv);
	} while (*++argv != NULL);
}
