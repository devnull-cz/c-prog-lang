#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv)
{
	assert(argc > 3);

	int n = atoi(argv[1]);
	argv = argv + 2;

	int *p = malloc(n * sizeof (int));
	assert(p != NULL);

	for (int i = 0; i < n; ++i) {
		if (*argv != NULL) 
			p[i] = atoi(*argv++);
		else
			p[i] = 0;
	}

	for (int i = 0; i < n; ++i)
		printf("%d ", p[i]);
	printf("\n");
	free(p);
}
