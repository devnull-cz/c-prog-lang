/*
 * Compile and run the program, observe what happens.
 * Then recompile it with the -DADDTWO and observe once again.
 * Why is that ?
 */

#include <stdio.h>

int
main(void)
{
	float f = 1 << 23;
	size_t cnt = 0;

	printf("%zu\n", sizeof (f));

	while (1) {
		printf("%16.2f %zu\n", f, cnt++);
#if ADDTWO
		if (f >= 16777216.0)
			f += 2;
		else
#endif
			f += 1;
	}
}
