#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <limits.h>

int
main(int argc, char *argv[])
{
	if (argc != 2)
		errx(1, "usage: %s <file>", argv[0]);

	FILE *fp;
	if ((fp = fopen(argv[1], "w+")) == NULL)
		err(1, "fopen");

	int a[3] = {INT_MAX, INT_MAX / 2, INT_MAX / 4};
	fwrite(a, sizeof (a[0]), sizeof (a) / sizeof (a[0]), fp);

	int in[3] = { 0 };
	rewind(fp);
	fread(in, sizeof (in[0]), sizeof (in) / sizeof (in[0]), fp);
	for (size_t i = 0; i < sizeof (in) / sizeof (in[0]); i++)
		fprintf(stderr, "%d\n", in[i]);

	fclose(fp);
}
