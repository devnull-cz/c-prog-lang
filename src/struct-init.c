#include <stdio.h>

struct foo_s {
	char a;
	int b;
};

int
main(void)
{
	struct foo_s foo = { 1, 'C' };

	/* Remember, char is expanded to int if passed to printf */
	printf("%d\n", foo.a);
	printf("%c\n", foo.b);
}
