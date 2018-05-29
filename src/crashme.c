#include <stdlib.h>
#include <stdio.h>

int
main(int argc, char **argv)
{
	int a, b;

	if (argc != 3)
		return (1);

	a = atoi(argv[1]);
	b = atoi(argv[2]);

	// printf("%d %d\n", a, b);

	return (b ? a / b : 0);
}
