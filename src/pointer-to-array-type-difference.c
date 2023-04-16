/*
 * While 'p' points "just" to an array with int elements, its type is different
 * if it points to 3 or 4 of such ints.
 *
 *	pointer-to-array-type-difference.c: In function ‘main’:
 *	pointer-to-array-type-difference.c:16:13: warning: passing argument 1 of
 *	‘myf’ from incompatible pointer type [-Wincompatible-pointer-types]
 *	   16 |         myf(p);
 *	      |             ^
 *	      |             |
 *	      |             int (*)[3]
 *	pointer-to-array-type-difference.c:6:16: note: expected ‘int (*)[4]’ but
 *	argument is of type ‘int (*)[3]’
 *	    6 | void myf(int (*p)[4])
 *	      |          ~~~~~~^~~~~
 *
 *
 * Note that having had a parameter "int p[3]" and passing in an "int p[4]"
 * would have been fine as 'p' would be converted to a pointer to an int but the
 * situation below is different.  We are passing in a pointer, not an array.
 */
#include <stdio.h>

void myf(int (*p)[4])
{
	(void)p;
}

int
main(void)
{
	int (*p)[3] = NULL;

	myf(p);
}
