#include <stdio.h>
#include <string.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define	BUFFER_SIZE	5
#endif

static void
corrupt(char *p, size_t len)
{
	char foo[4] = "AAA";

	printf("%zu vs %zu\n", sizeof (foo), len);
	printf("before: %s\n", foo);

	/*
	 * Note that strncpy() does not terminate the target string if the
	 * source string does not contain the NUL byte within the first n bytes,
	 * where n is the size of the target buffer.
	 */
	strncpy(foo, p, len);

	/*
	 * Try to do something with the target buffer to make sure it is not
	 * optimized away.
	 */
	printf("after: %s\n", foo);

	/* Demonstrate that the program is still alive. */
	sleep(3);
}

int
main(void)
{
	char bar[128];

	/* The initialization seems to foil Clang static checker. */
#if 0
	char bar[BUFFER_SIZE];

	for (size_t i = 0; i < sizeof (bar); i++)
		bar[i] = 'X';
	bar[sizeof (bar) - 1] = '\0';
#endif

	/* BUG: may overflow the buffer in corrupt()! */
	corrupt(bar, sizeof (bar));
}
