/*
 * This may result with a bus error on some architectures when running (it will
 * compile fine).  E.g., SPARC.
 *
 *	$ ./a.out
 *	Bus Error (core dumped)
 *
 *	$ echo $?
 *	138
 *
 *	$ isainfo
 *	sparcv9 sparc
*/
#include <stdio.h>

int
main(void)
{
	char *s = "hello, world, hello, world";
	long long int *p = (long long int *)(s + 1);

	printf("%lld\n", *p);
}
