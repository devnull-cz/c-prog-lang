#include <stdio.h>

int
main(void)
{
	{ // start of block (compound statement)
		int i = 8;	// variable declaration with initialization
		printf("%d\n", i);	// expression statement
	} // end of block
	int i = 12;	// reuse

	return (i);
}
