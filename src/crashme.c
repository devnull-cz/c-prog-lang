#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv)
{
	int a, b;

	assert(argc == 3);

	a = atoi(argv[1]);
	b = atoi(argv[2]);

	printf("%d %d\n", a, b);

	return (b ? a / b : 0);
}
