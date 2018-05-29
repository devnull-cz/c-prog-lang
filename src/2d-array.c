#include <stdio.h>

void
func(int array[][2], size_t size)
{
	int i;

	printf("sizeof = %zu\n", sizeof (array[0]));
	for (i = 0; i < size; i++) {
		printf("%d\n", array[i][0]);
	}
}

int
main(void)
{
	int a[4][2] = { {5, 6} , {7, 8}, {9, 10} };

	func(a, 4);

	return (0);
}
