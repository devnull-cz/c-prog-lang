#include <stdlib.h>

#include "opaque_impl.h"

struct opaque *
getOpaque(void)
{
	return (malloc(sizeof (struct opaque)));
}

void
doStuff(struct opaque *f)
{
	f->x = 1;
	f->y = 2;
}
