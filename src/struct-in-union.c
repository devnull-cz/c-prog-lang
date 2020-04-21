#include <stdio.h>

int
main(void)
{
	union foo {
		struct { // anonymous struct
			int a;
			int b;
		} s1;
		struct { // ditto
			short sa_1;
			short sa_2;
			short sb_1;
			short sb_2;
		} s2;
	} foo;

	foo.s1.a = 42;
	printf("%d %d\n", foo.s2.sa_1, foo.s2.sa_2);

	return (0);
}
