#include <stdio.h>

int
main(int argc, char **argv)
{
	(void)argc;

	while (*argv++ != NULL) {
		printf("'%s'\n", *(argv - 1));
	}
}
