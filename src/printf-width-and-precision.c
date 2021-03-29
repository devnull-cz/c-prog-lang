/*
 * On the use of the width and precision in the conversion specifier with
 * integers and strings.
 */
#include <stdio.h>

char *s = "0123456789abcdef";

int
main(void)
{
	/*
	 * With a string, the precision is a _maximum_ number of characters
	 * printed.  We get "0123456789" here.
	 */
	(void) printf("%.10s\n", s);
	/*
	 * If the precision is more than the string length, the full string is
	 * printed; so we get "x" here.
	 */
	(void) printf("%.10s\n", "x");
	/*
	 * We can align a string to the left, print it with the greater width,
	 * and not print all of it.  We will get here:
	 *
	 *	:hello, wor     :
	 */
	(void) printf(":%-15.10s:\n", "hello, world");
	/*
	 * When printing out an integer, the precision is a _minimum_ number of
	 * digits printed.  It is automatically padded with 0 if the number is
	 * not long enough.  So we get "0000000013" here.
	 */
	(void) printf("%.10lu\n", (unsigned long)13);
	/*
	 * However, as the precision drives the minimum number of digits
	 * printed, if the precision is less than the integer len, the full
	 * number is still printed.  That is expected.  We will get "999" below.
	 */
	(void) printf("%.2d\n", 999);
	/*
	 * When the minimum width conversion is used, the following is the same
	 * thing as "%.10lu" above.  We get "0000000013".
	 */
	(void) printf("%010lu\n", (unsigned long)13);
	/*
	 * When the number is not large enough and no padding is set, it will be
	 * padded with spaces on the left (or right if '-' is used).
	 */
	(void) printf("%5d\n", 1);
	/* ...or right if '-' is used. */
	(void) printf("%-5d:\n", 1);
	/*
	 * As with the precision, the width specification is the _minimal_ width
	 * only.  It does not specify any upper limit.  In the following two
	 * examples, there is effectively no padding.
	 */
	(void) printf("%-5d:\n", 1111111111);
	(void) printf("%5d:\n", 1111111111);
}
