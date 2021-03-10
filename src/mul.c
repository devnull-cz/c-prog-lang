/*
 * compile with and without -DPARENS and see the difference.
 */

#include <stdio.h>

#ifdef PARENS
#define MUL(a, b) ((a) * (b))
#else
#define MUL(a, b) (a * b)
#endif

int
main(void)
{
	int i = 2, j = 3;
	printf("%d\n", MUL(i + j, 3));
}
