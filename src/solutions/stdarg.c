/*
 * To see the effect (on x86), compile as 32-bit program.
 */

#include <stdio.h>
#include <stdarg.h>

size_t
f(int count, ...)
{
	va_list ap;
	size_t sum = 0;

	va_start(ap, count);
	for (int i = 0; i < count; i++) {
		unsigned long long val = va_arg(ap, unsigned long long);
		printf("%llu\n", val);
		sum += val;
	}
	va_end(ap);

	return (sum);
}

int
main(void)
{
	printf("%zu\n", f(3, 1ULL, 2147483647, 3ULL));
}
