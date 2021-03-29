#include <stdio.h>

int
main(void)
{
	{
		char s[8] = { 'h' }; // The rest will be initialized with zeroes

		/* Sizeof returns the size of the whole array in bytes. */
		printf("size = %zu\n", sizeof (s));
		for (size_t i = 0; i < sizeof (s); i++)
			printf("'%c' (0x%x)\n", s[i], s[i]);
		printf("%s\n", s);
	}

	/*
	 * The following block of code will print the strings, possibly some
	 * garbage after them, then it might crash.
	 */
	{
		// Note the terminating NUL is missing!
		char s[] = { 'f', 'o', 'o' };
		char p[] = { 'b', 'a', 'r' }; // ditto !

		printf("size = %zu\n", sizeof (s));
		for (size_t i = 0; i < sizeof (s); i++)
			printf("'%c' (0x%x)\n", s[i], s[i]);
		printf("p = %s\n", p);
		printf("s = %s\n", s);
	}
}
