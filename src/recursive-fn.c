/*
 * Print 0..9 recursively using a function call fn(9).
 */
#include <stdio.h>

void
myfn(int depth)
{
	if (depth != 0)
		myfn(depth - 1);
	printf("%d\n", depth);
}

int
main(void)
{
	myfn(9);
}
