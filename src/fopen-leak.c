#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <limits.h>

int
main(int argc, char *argv[])
{
	if (argc != 2)
		errx(1, "usage: %s <file>", argv[0]);

	for (size_t i = 1; i < UINT_MAX; i++) {
		FILE *f = fopen(argv[1], "r");
		if (f == NULL)
			err(1, "fopen [%zu]", i);
	}
}
