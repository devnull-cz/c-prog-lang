#include <stdio.h>
#include <limits.h>

/*
 * Let's assume that:
 *
 *      short int is 2 bytes
 *      int is 4 bytes
 *      long is 8 bytes
 *      long long is 8 bytes
 *
 * Compile with "gcc -m64" to match the above.
 *
 * Let's assume that we use gcc that uses modulo to fit when assigning to a
 * signed integer.
 *
 * Include <limits.h> for INT_MIN (-2^31) and INT_MAX (2^31 - 1).
 */

/*
 * Use bc(1) to manually compute the values of the left sides.  When done,
 * incorporate into the C code, compile, and verify you got it right.
 *
 * You will get warnings when compiling this.
 */

unsigned long long ull = -13;		  // Use %llu in printf() to verify.
signed char c = 999;			  // %d
short int si = -1;			  // %hd
unsigned int u = -1;			  // %u
unsigned short int usi = 999999;	  // %hu
signed char c2 = 0 ? -10 : 0U;		  // %d
signed char c3 = -1 ? -10 : 0U;		  // %d
long long ll = 1U + -10;		  // %lld
unsigned long long ull2 = 1U + -10;	  // %llu
unsigned short int usi2 = INT_MIN + 13LU; // %hu
unsigned short int usi3 = -INT_MAX + 13U; // %hu
signed char c4 = 129;			  // %d

int
main(void)
{
	printf("%llu\n", ull);
	printf("%d\n", c);
	printf("%hd\n", si);
	printf("%u\n", u);
	printf("%hu\n", usi);
	printf("%d\n", c2);
	printf("%d\n", c3);
	printf("%lld\n", ll);
	printf("%lld\n", ull2);
	printf("%hu\n", usi2);
	printf("%hu\n", usi3);
	printf("%d\n", c4);
}
