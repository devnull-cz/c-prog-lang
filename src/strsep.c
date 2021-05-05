#include <stdio.h>
#include <string.h>

int
main(void)
{
	char *p;
	char str[] = "foo,,bar";  // There is good reason this is array.
	char *end = str + strlen(str) + 1;
	char *inputstr = str;
	char *delim = ",";

	while ((p = strsep(&inputstr, delim)) != NULL) {
		printf("'%s'\n", p);
	}

	// Print the original string to see how it changed.
	for (p = str; p < end; p++)
		printf("%hhx ", *p);
	printf("\n");
}
