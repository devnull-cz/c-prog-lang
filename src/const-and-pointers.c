#include <stddef.h>
/*
 * The difference between a const pointer and a pointer to a const.
 *
 *	In function main:
 *	error: assignment of read-only location p
 *	  *p = 'a';
 *	     ^
 *	error: assignment of read-only variable p2
 *	  p2 = NULL;
 *	     ^
 */

int
main(void)
{
	char c;
	/* pointer to const char */
	const char *p = &c;
	/* const pointer to char */
	char *const p2 = &c;

	/* Illegal, cannot change a const char. */
	*p = 'a';
	/* Legal, the pointer itself is not a const. */
	p = NULL;

	/* Legal, what p2 points to is not a const. */
	*p2 = 'b';
	/* Illegal as p2 itself is a const. */
	p2 = NULL;

	return (0);
}
