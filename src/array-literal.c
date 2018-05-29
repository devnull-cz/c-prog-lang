#include <stdio.h>

void
func(int array[], size_t len)
{
	for (int i = 0; i < len; i++)
		printf("%d\n", array[i]);
}

int
main(void)
{
	func((int []){ 0, 1, 2}, 3);

	return (0);
}
