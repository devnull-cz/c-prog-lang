#include <stdio.h>
#include <stdlib.h>
#include <err.h>

int
main(void)
{
	char c;
	FILE *in, *out;

	/* Choose any other file you have on your system. */
	if ((in = fopen("/etc/passwd", "r")) == NULL)
		err(1, "fopen: input");

	if ((out = fopen("copy", "w+")) == NULL)
		err(1, "fopen: output");

	/*
	 * fread() returns a number of *items* read.  In our case, it's the same
	 * as number of bytes as we read it one byte at a time.
	 */
	while (fread(&c, sizeof (c), 1, in) == 1) {
		fwrite(&c, sizeof (c), 1, out);
		if (ferror(out)) {
			fprintf(stderr, "failed to write\n");
			break;
		}
	}

	fclose(in);
	fclose(out);
}
