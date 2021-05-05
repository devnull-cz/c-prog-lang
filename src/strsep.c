#include <stdio.h>
#include <string.h>

static void
print_hex(char *ident, char *str, char *end)
{
	char *p;

	for (p = str; p < end; p++)
		printf("%2hhx ", *p);

	printf("\n");
}

int
main(void)
{
	char *p;
	char str[] = "foo,,bar";  // There is good reason this is array.
	char *end = str + strlen(str) + 1;
	char *inputstr = str;
	char *delim = ",";

	// Print the original string.
	print_hex("before: ", str, end);

	while ((p = strsep(&inputstr, delim)) != NULL) {
		printf("'%s'\n", p);
	}

	// Print the original string to see how it changed.
	print_hex("after: ", str, end);
}
