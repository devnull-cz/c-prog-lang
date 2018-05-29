#include <stdio.h>

int
main(void)
{
	char a[] = "hello";

	/* Will print 'e' */
	printf("%c\n", *(a + 1));
}
