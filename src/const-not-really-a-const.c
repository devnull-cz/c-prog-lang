#include <stdio.h>

int
main(void)
{
	int i = 'c';
	int *i1 = &i;
	int const *i2 = &i;

	// Illegal.  I cannot change 'i' through *i2.
	*i2 = 'x';
	// However, I can change it through *i1.
	*i1 = 'x';
}
