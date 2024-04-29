#include <stdio.h>

struct Common { int type; };
struct A      { int type; char data[8]; };  // type == 1
struct B      { int type; char data[16]; }; // type == 2

// Return the size of the real/underlying structure.
size_t
func(struct Common *c) {
	int r = -1;

	if (c->type == 1) {
		r = sizeof (((struct A *)c)->data);
	} else if (c->type == 2) {
		r = sizeof (((struct B *)c)->data);
	}

	return (r);
}

int
main(void)
{
	struct A a = { .type = 1 };
	struct B b = { .type = 2 };

	(void) printf("%zu\n", func((struct Common *)&a));
	(void) printf("%zu\n", func((struct Common *)&b));
}
