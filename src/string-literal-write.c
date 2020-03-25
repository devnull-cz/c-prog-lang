#include <stdio.h>

char *s = "foo";

int
main(void)
{
	// causes segmentation failure (with GCC)
	s[0] = 'A';

	printf("%s\n", s);

	return (0);
}
