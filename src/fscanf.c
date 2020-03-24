#include <stdio.h>
#include <stdlib.h>
#include <err.h>

int
main(int argc, char *argv[])
{
	if (argc != 2)
		errx(1, "usage: %s <file>", argv[0]);

	FILE *fp;
	if ((fp = fopen(argv[1], "r")) == NULL)
		err(1, "fopen");

	int num;
	char str[BUFSIZ]; // might not be enough
	while (fscanf(fp, "%d %s\n", &num, str) > 0)
		printf("%d '%s'\n", num, str);

	fclose(fp);
	return (0);
}
