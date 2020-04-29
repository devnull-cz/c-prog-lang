#include <stdio.h>

int
main(void)
{
	int i = 'c';
	int *p1 = &i;
	int const *p2 = &i;

	// Illegal.  I cannot change 'i' through *p2.
	*p2 = 'x';
	// However, I can change it through *p1.
	*p1 = 'x';
}
