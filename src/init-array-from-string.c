#include <stdio.h>

char array[] = "foobar";

int
main(void)
{
	printf("Array size: %zu\n", sizeof (array));
	printf("Array as string: '%s'\n", array);
}
