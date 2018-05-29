#include <stdio.h>

struct foo_s {
	char a;
	int b;
	short c;
	void *p;
};

int
main(void)
{
	/* define structure using 'designated initializers' from C99 */
	struct foo_s foo = {
	    .b = 'C',
	    .a = 1
	};

	printf("foo bar %p\n", &foo);
	/* Will be implicitly 0 */
	printf("%d\n", foo.c);
	/* Will be implicitly NULL (0) */
	printf("%p\n", foo.p);

	return (0);
}
