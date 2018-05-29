#include <stdio.h>

void
fn(void)
{
	static int i = 0;

	printf("%d\n", ++i);
}

int
main(void)
{
	fn();
	fn();
	fn();
	fn();
}
