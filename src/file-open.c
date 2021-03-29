#include <stdio.h>
#include <stdlib.h>
#include <err.h>

static void
file_read(char *file, size_t len)
{
	// No error check or error reporting, grr.
	FILE *fp = fopen(file, "r");

	char *mem = calloc(len, sizeof (char));
	fread(mem, sizeof (char), len, fp);
	printf("%s\n", mem);
}

int
main(int argc, char *argv[])
{
	if (argc != 3)
		errx(1, "usage: %s <file> <bytecnt>", argv[0]);

	for (size_t i = 0; i < 16384; i++)
		file_read(argv[1], atoi(argv[2]));
}
