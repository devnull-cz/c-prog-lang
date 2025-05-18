#include <stdio.h>

#include "opaque.h"

int
main(void)
{
	opaque_t h; // has to be a pointer

	// will not compile:
	// printf("%zu\n", sizeof (struct opaque));

	h = getOpaque();
	doStuff(h);
}
