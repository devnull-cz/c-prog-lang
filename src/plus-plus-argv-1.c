#include <stdio.h>

int
main(int argc, char **argv)
{
	printf("%s\n", ++*++argv);
	printf("%s\n", ++*++argv);

	return (0);
}
