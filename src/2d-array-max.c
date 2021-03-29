/*
 * Write a program that takes a 2-D array of integers and constructs a 1-D array
 * of maximum values in each sub-array.
 *
 * In a separate loop, print out the new array to the standard output.
 *
 * For the maximum value in a sub-array, write a function.
 */

#include <stdio.h>

int
getmax(int a[], size_t size)
{
	int max = a[0];

	for (size_t i = 0; i < size; i++) {
		if (a[i] > max)
			max = a[i];
	}

	return (max);
}

int
main(void)
{
	int a[][2] = { {5, 6}, {8, 7}, {9, 10} };
	int amax[sizeof (a) / sizeof (a[0])];

	for (size_t i = 0; i < sizeof (a) / sizeof (a[0]); i++)
		amax[i] = getmax(a[i], sizeof (a[0]) / sizeof (a[0][0]));

	for (size_t i = 0; i < sizeof (amax) / sizeof (amax[0]); ++i)
		printf("%d\n", amax[i]);
}
