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

	// not a integral promotion but a x86 API manifestation
	func(c);

	return (0);
}
