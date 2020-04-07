#include <stdio.h>

struct {
	int a[42];
	char *b;
} foo = { .a = { 1, 2, 3 }, .b = "ABC" };

int
main(void)
{
	printf("a = %p\n", foo.a);
	printf("b = %p (%s)\n", foo.b, foo.b);

	printf("&a[2] = %p\n", &foo.a[2]);
	printf("3rd char from b = %c\n", *(foo.b + 2));
	printf("3rd char = %p\n", foo.b + 2);

	return (0);
}
