#include <err.h>
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv)
{
	if (argc != 2)
		errx(1, "Need one argument.");

	int c = atoi(*++argv);

	switch (c) {
	case 2:
		printf("Number Two was here.\n");
		break;
	case 'X':
		printf("Number One was here.\n");
		break;
	case 3:
	case 4:
		printf("Number Three or Four was here.\n");
		break;
	default:
		printf("Unknown number: %d\n", c);
		exit(1);
	}
}
