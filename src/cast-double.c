#include <stdio.h>

int
main(void)
{
	int a = 5;

	printf("%d\n", a / 3);

	/*
	 * The following is wrong and the compiler will probably warn you about
	 * it.  We are putting an integer on a stack (32-bit ABI) or to a
	 * register (64-bit ABI) but the function takes "sizeof (double)" bytes
	 * and interpret them as a double floating point number.
	 */
	printf("%f\n", a / 3);

	/*
	 * To get the right result, we need to cast it (or pass a double
	 * directly).
	 *
	 * The cast operator has a higher precedence than division so the
	 * conversion of 'a' takes place first, then the divisor is implicitly
	 * converted.
	 */
	printf("%f\n", (double)a / 3);

	/* Also works but that's not the point we are making here. */
	printf("%f\n", a / 3.0);

	/*
	 * This is fine as well but note that first we do 5/3 in integer
	 * arithmetics, and the result is casted to double.  So, the result will
	 * be 1.
	 */
	printf("%f\n", (double)(a / 3));
}
