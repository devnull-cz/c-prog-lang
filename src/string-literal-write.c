#include <stdio.h>

char *s = "foo";
char a[] = "bar";

int
main(void)
{
	a[0] = 'A';
	printf("%s\n", a);

	/* causes segmentation failure (with GCC) */
	s[0] = 'B';
	printf("%s\n", s);
}
