#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <limits.h>

#include "animals.h"
#include "animal_minlegs.h"

int
main(int argc, char *argv[])
{
	if (argc != 2)
		errx(1, "usage: %s <number_of_legs>", argv[0]);

	printf("count: %zu\n",
	    count_minlegs(animals, sizeof (animals) / sizeof (animals[0]),
	    atoi(argv[1])));

	return (0);
}
