#define	MYOFFSETOF(s, m)	\
	(size_t)(&((s *)0)->m)

#include <stdio.h>

int
main(void)
{
	struct X { char a; int b; char c; };

	printf("%zu\n", MYOFFSETOF(struct X, c));

	return (0);
}
