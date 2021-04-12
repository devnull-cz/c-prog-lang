#include <stdio.h>

int
main(void)
{
	char s[8] = { 'h' }; // The rest will be initialized with zeroes

	/* sizeof returns the size of the whole array in bytes. */
	printf("size = %zu\n", sizeof (s));
	for (size_t i = 0; i < sizeof (s); i++)
		printf("'%c' (0x%x)\n", s[i], s[i]);
	printf("%s\n", s);
}
