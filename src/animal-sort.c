#include <stdio.h>
#include <string.h> // strcmp()
#include <stdlib.h> // qsort()
#include <stdlib.h>
#include <err.h>
#include <limits.h>

#include "animal.h"
#include "animals.h"

static int
name_cmp(const void *a, const void *b)
{
	return (strcmp(((struct animal *)a)->name,
	    ((struct animal *)b)->name));
}

static int
legs_cmp(const void *first, const void *second)
{
	struct animal *a = (struct animal *) first;
	struct animal *b = (struct animal *) second;

	if (a->legs < b->legs)
		return (-1);
	else if (a-> legs > b->legs)
		return (1);
	else
		return (0);
}

int
main(int argc, char *argv[])
{
	size_t i;

	int (*compare_f)(const void *, const void *);

	if (argc != 2)
		errx(1, "usage: %s <0|1>", argv[0]);

	switch (atoi(argv[1])) {
		case 0:
			compare_f = name_cmp;
			break;
		case 1:
			compare_f = legs_cmp;
			break;
		default:
			errx(1, "bad argument");
	}

	printf("Sorting...\n");
	qsort(animals, sizeof (animals) / sizeof (animals[0]),
	    sizeof (animals[0]), compare_f);
	printf("done\n");

	printf("\nresult:\n");
	for (i = 0; i < sizeof (animals) / sizeof (animals[0]); i++) {
		printf("%s %zu\n", animals[i].name, animals[i].legs);
	}

	return (0);
}
