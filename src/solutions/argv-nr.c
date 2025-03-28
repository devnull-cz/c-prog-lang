#include <assert.h>
#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char *argv[])
{
	if (argc < 3)
		errx(1, "usage: %s <arg_idx> <char_idx> arg1 [arg2..]", *argv);

	int arg_idx = atoi(argv[1]);
	int char_idx = atoi(argv[2]);

	assert(arg_idx > 0);
	assert(char_idx > 0);

	/* Skip argv[0], arg_idx, and char_idx. */
	argv += 3;

	if (3 + arg_idx > argc - 1)
		errx(1, "1st arg must be at most %d.", argc - 4);

	size_t n = strlen(*(argv + arg_idx));
	if ((size_t)char_idx > n - 1)
		errx(1, "2nd arg must be at most %zu.", n - 1);

	printf("%c\n", *(*(argv + arg_idx) + char_idx));
}
