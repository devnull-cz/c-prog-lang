/*
 * There are more ways how to print the command line arguments.
 */
#include <stdio.h>

/*
 * Also remember, argv is an *array* of some objects, so as its a function
 * parameter, the compiler is take is as a pointer.  So, you could also use:
 *
 *	main(int argc, char **argv)
 */
int
main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; ++i)
		printf("%s\n", argv[i]);
	printf("--\n");

	i = 0;
	while (argv[i] != NULL)
		printf("%s\n", argv[i++]);
	printf("--\n");

	while (*argv != NULL)
		printf("%s\n", *argv++);
}
