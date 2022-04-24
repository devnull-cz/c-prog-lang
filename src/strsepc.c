/*
 * Implement strsep() but only use a single delimiter.
 *
 * char *strsepc(char **stringp, int c);
 */
#include <stdio.h>
#include <assert.h>

char *
strsepc(char **stringp, int c)
{
	char *orig = *stringp;
	char *s = *stringp;

	if (s == NULL)
		return (NULL);

	while (*s != '\0' && *s != c) {
#if 0
		printf("%c\n", *s); // debug print
#endif
		s++;
	}

	/*
	 * The pointer to the next character after the delimiter character (or
	 * NULL, if the end of the string was reached) is stored in *stringp.
	 */
	if (*s != '\0') {
		*s = '\0';
		*stringp = s + 1;
	} else {
		*stringp = NULL;
	}

	/* The original value of *stringp is returned. */
	return (orig);
}

int
main(int argc, char **argv)
{
	char *orig, *new;

	assert(argc == 3);
#if 1
	new = argv[1];
#else
	/* This may crash the process based on what compiler you use. */
	new = "foo,bar";
#endif

	while ((orig = strsepc(&new, argv[2][0])) != NULL) {
		printf("%s\n", orig);
	}
}
