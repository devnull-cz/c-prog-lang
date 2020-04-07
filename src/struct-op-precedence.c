#include <stdio.h>

struct bar {
	int val;
} bar = { .val = 42 };

struct {
	int a[42];
	char *b;
	struct bar *c;
} foo = { .a = { 1, 2, 3 }, .b = "ABC", .c = &bar };

int
main(void)
{
	printf("a = %p\n", foo.a);
	printf("b = %p (%s)\n", foo.b, foo.b);
	printf("&a[2] = %p\n", &foo.a[2]);
	printf("3rd char from b = %c\n", *(foo.b + 2));
	printf("3rd char = %p\n", foo.b + 2);
	printf("val = %d\n", foo.c->val);
	printf("&val = %p\n", &(foo.c->val));

	return (0);
}
