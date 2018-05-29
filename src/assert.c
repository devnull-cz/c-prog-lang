#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Custom assert macro, overrides the library function assert(3).
#define	assert(p)	if (!(p)) {					\
	fprintf(stderr, "assert failed at %d in %s\n", __LINE__, __FILE__);	\
	exit(1); }

int
main(int argc, char *argv[])
{
	assert(argc == 2);

	return (0);
}
