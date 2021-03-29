#include <stdio.h>

void
func(int a)
{
	printf("%d\n", a);
}

int
main(void)
{
	unsigned char c = 'A';

	/* not an integral promotion but an x86 API manifestation */
	func(c);
}
