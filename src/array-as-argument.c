#include <stdio.h>

/*
 * The "a" parameter will be treated as (char *).  sizeof (a) will be sizeof
 * (char *).
 *
 * You can even increment "a" which is not possible with arrays.  Why is it so
 * confusing?  Historical reasons and backward compatibility requirements in
 * order not to make existing code not compilable.
 */
void
myfn(char a[20])
{
	/* Will actually print sizeof (char *) */
	printf("%zu\n", sizeof (a));
	printf("%p\n", a);
	/* "a" is treated as a pointer */
	printf("%p\n", ++a);
}

int
main(void)
{
	char *s = "hello, world";

	myfn(s);
}
