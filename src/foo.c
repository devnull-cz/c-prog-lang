#include <stdlib.h>

struct foo {
    int x;
    int y;
};

struct foo *
getFoo(void)
{
	return (malloc(sizeof (struct foo)));
}

void
doStuff(struct foo *f)
{
	f->x = 1;
	f->y = 2;
}
