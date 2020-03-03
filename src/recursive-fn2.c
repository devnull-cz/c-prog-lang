/*
 * Print 9..0 recursively using a function call fn(9).
 */
#include <stdio.h>

void
myfn(int depth)
{
	printf("%d\n", depth);
	/*
	 * Also try to remove ';' after return, compile, and explain what you
	 * see.
	 */
	if (depth == 0)
		return;
	myfn(depth - 1);
}

int
main(void)
{
	myfn(9);
}
