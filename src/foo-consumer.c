#include <stdio.h>

#include "foo.h"

int
main(void)
{
	foo_t h; // has to be a pointer

	// will not compile:
	// printf("%zu\n", sizeof (struct foo));

	h = getFoo();
	doStuff(h);
}
