#include <stdio.h>

int
myadd(int a, int b)
{
        return (a + b);
}

int
mymultiply(int a, int b)
{
        return (a * b);
}

int
process_numbers(int a, int b, int (*f)(int, int))
{
        return ((*f)(a, b));
}

int
main(void)
{
	printf("%d\n", process_numbers(13, 7, myadd));
	printf("%d\n", process_numbers(13, 7, mymultiply));
}
