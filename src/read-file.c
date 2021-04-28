#include <stdio.h>
#include <stdlib.h>
#include <err.h>

int
main(void)
{
	char c;
	FILE *fp;

	/* Choose any other file you have on your system. */
	if ((fp = fopen("/etc/passwd", "r")) == NULL)
		err(1, "fopen");

	/*
	 * fread() returns a number of *items* read.  In our case, it's the same
	 * as number of bytes as we read it one byte at a time.
	 */
	while (fread(&c, sizeof (c), 1, fp) == 1) {
		putchar(c);
	}

	fclose(fp);
}
