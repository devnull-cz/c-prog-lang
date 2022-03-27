#include <stdio.h>

char *s = "foo";
char a[] = "bar";

int
main(void)
{
	a[0] = 'B';
	printf("%s\n", a);

	/* causes segmentation failure (with GCC) */
	s[1] = 'A';
	printf("%s\n", s);
}
