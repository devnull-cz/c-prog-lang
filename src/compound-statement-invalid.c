#include <stdio.h>

int
main(void)
{
	int i = 2;

	if (({ i *= 2; puts("doubled");}), i % 2 == 0) {
		puts("even");
	} else {
		puts("odd");
	}
	printf("%d\n", i);
}
