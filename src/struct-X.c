/* compile with and without -fpack-struct and observe the difference */

#include <stdio.h>

struct X { int a; char b; int c; };
struct Y { int a; char b; int c; char d; };
struct Z { int a; char b; int c; char *d; };

int
main(void)
{
	printf("%zu\n", sizeof (struct X));
	printf("%zu\n", sizeof (struct Y));
	printf("%zu\n", sizeof (struct Z));
}
