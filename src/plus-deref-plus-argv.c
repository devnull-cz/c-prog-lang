#include <stdio.h>

int
main(int argc, char **argv)
{
	/*
	 * Assuming we run this as:
	 *
	 *	$ ./a.out hello dear friend
	 *
	 * What will be printed?
	 */
	printf("%s\n", argv[1]);
	printf("%s\n", ++*++argv);
	printf("%s\n", argv[0]);
	printf("%s\n", ++*++argv);
	printf("%s\n", argv[0]);

	return (0);
}
