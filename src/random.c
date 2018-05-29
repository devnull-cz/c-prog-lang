#include <stdlib.h>
#include <time.h>

#define	SIZE	8

void
run(void)
{
	char *p[SIZE] = { 0 };

	long int idx = random() % SIZE;

	for (size_t i = 0; i < SIZE; i++) {
		if (i == idx)
			**(p + idx) = 'a';
	}
}

int
main(void)
{

	srandom(time(NULL));

	run();

	return (0);
}
