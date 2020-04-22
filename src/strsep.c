#include <stdio.h>
#include <string.h>

int
main(void)
{
	char *p;
	char str[] = "foo,bar";
	char *inputstr = str;
	char *delim = ",";

	while ((p = strsep(&inputstr, delim)) != NULL) {
		printf("%s\n", p);
	}

	return (0);
}
