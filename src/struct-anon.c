// compile with: -Wall -pedantic -std=c99

#include <stdio.h>

int
main(void)
{
	struct {
		struct {
			int a;
			char b;
		};
	} foo;

	foo.a = 42;
	printf("%d\n", foo.a);
}
