#include <stdio.h>

int
main(void)
{
	char *a[] = { "hello", ",", " world", "!" };

	printf("size = %zu\n", sizeof (a));
	printf("%s%s%s%s\n", a[0], a[1], a[2], a[3]);
}
