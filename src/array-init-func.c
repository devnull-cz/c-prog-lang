#include <stdio.h>

int
func(void)
{
	static int val = 1;

	return (val++);
}

int
main(void)
{
	int a[3] = { func(), func(), func() };

	for (size_t i = 0; i < sizeof (a) / sizeof (a[0]); i++)
		printf("%d\n", a[i]);
}
