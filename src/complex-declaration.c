#include <stddef.h>

/* foo and foo2 are compatible types */
typedef char *(*(**foo[][8])())[];

typedef char *a_of_p[];
typedef a_of_p *(**foo2[][8])();

int
main(void)
{
	foo x = { NULL};
	foo2 y = { NULL};

	/*
	 * The compiler may warn that x and y may never be equal but it accepts
	 * they are of the same type.
	 */
	if (y == x)
		return (1);

	return (0);
}
