/*
 * The code will print strings, possibly some garbage after them, then it might
 * crash.  It may also look like it just works fine.
 */
#include <stdio.h>

int
main(void)
{
	/* Note the terminating NULs are missing! */
	char s[] = { 'f', 'o', 'o' };
	char p[] = { 'b', 'a', 'r' };

	printf("size = %zu\n", sizeof (s));
	for (size_t i = 0; i < sizeof (s); i++)
		printf("'%c' (0x%x)\n", s[i], s[i]);
	printf("p = %s\n", p);
	printf("s = %s\n", s);
}
