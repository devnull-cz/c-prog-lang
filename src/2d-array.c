#include <stdio.h>

void
func(int array[][2], size_t size)
{
	printf("sizeof = %zu\n", sizeof (array[0]));

	int i = 0;
	while (i < size) {
		printf("%d\n", array[i][0]);
		i++;
	}
}

int
main(void)
{
	int a[4][2] = { {5, 6} , {7, 8}, {9, 10} };

	func(a, 4);

	return (0);
}
