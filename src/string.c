#include <stdio.h>

char *string = "foo";
char array[] = "bar";

int
main(void)
{
	printf("modifying string\n");
	string[0] = 'A';

	printf("modifying array\n");
	array[0] = 'A';

	return (0);
}
