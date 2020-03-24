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
	if ((fp = fopen(argv[1], "r")) == NULL)
		err(1, "fopen");

	fseek(fp, 0, SEEK_END);
	long filesize = ftell(fp);
	printf("size = %ld\n", filesize);

	int val;
	fseek(fp, -sizeof (val), SEEK_END);
	for (int i = 0; i < filesize / sizeof (val); i++) {
		fread(&val, sizeof (val), 1, fp);
		fprintf(stderr, "%d\n", val);
		fseek(fp, - 2 * sizeof (val), SEEK_CUR);
	}

	fclose(fp);
	return (0);
}
