#include <stdio.h>

int
main(int argc, char **argv)
{
	while (*argv++ != NULL) {
		printf("'%s'\n", *(argv - 1));
	}
}
