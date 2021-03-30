/*
 * Print the first element from each line.
 */
#include <stdio.h>

/*
 * Remember, an array in C is just a piece of consequtive memory, and it does
 * not carry around any information about its size.  So, we must either know how
 * many lines (= the first dimension) is there, or provide it as an argument.
 *
 * Any other dimensions short of the 1st one must be exactly specified otherwise
 * the compiler will complain about an incomplete type (= type whose size cannot
 * be determined).
 */
void
func(int array[][2], size_t nlines)
{
	printf("sizeof for the array element (int [2]) = %zu\n",
	    sizeof (array[0]));

	int i = 0;
	while (i < nlines) {
		printf("%d\n", array[i][0]);
		i++;
	}
}

int
main(void)
{
	int a[4][2] = { {5, 6}, {7, 8}, {9, 10} };

	func(a, sizeof (a) / sizeof (a[0]));
}
