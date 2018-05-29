#include <stdio.h>

int
main(void)
{
	char *s;

	printf("%p\n", s = "hello world");
	printf("%s\n", s);
}
