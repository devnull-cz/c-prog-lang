#include <stdio.h>

int
main(void)
{
	float f;

	f = 13.12345678;

	printf("%f\n", f);
	printf("%.8f\n", f);
	printf("%.2f\n", f);
	printf("%10.2f\n", f);
	printf("%010.2f\n", f);
}
