#include <stdio.h>

#include "foo.h"

int
main(void)
{
	struct foo *foo; // has to be a pointer

	// will not compile:
	// printf("%zu\n", sizeof (struct foo));

	foo = getFoo();
	doStuff(foo);
}
