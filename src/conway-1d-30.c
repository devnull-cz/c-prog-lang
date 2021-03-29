/*
 * Conway's game of life implementation for 1-D using the rule 30.
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>	// memcpy()
#include <stdlib.h>	// abort()
#include <unistd.h>	// sleep()

#define	WIDTH		31 // use 80 to fit on standard terminal
#define	MAXITER		16

int world[WIDTH] = { [WIDTH / 2] = 1 };
int next[WIDTH];

int patterns[8][3] = { {1, 1, 1}, {1, 1, 0}, {1, 0, 1}, {1, 0, 0},
		       {0, 1, 1}, {0, 1, 0}, {0, 0, 1}, { 0 } };
int values[8] = { 0, 0, 0, 1, 1, 1, 1, 0 };

/*
 * Compare given array with patterns in global variable 'patterns'
 * and return the index.
 */
int
getval(int a[3])
{
	for (size_t i = 0; i < sizeof (patterns) / sizeof (patterns[0]); i++) {
		bool found = true;

		for (int j = 0; j < 3; j++) {
			if (a[j] != patterns[i][j]) {
				found = false;
				break;
			}
		}

		if (found)
			return (i);
	}

	abort();
}

/*
 * Get value of the array at index idx with wrap around.
 * Otherwise does not perform bounds checking.
 */
int
get(int a[], size_t len, int idx)
{
	if (idx == -1)
		return (a[len - 1]);
	else if (idx == len)
		return (a[0]);
	else
		return (a[idx]);
}

/* Prints the world global variable as one line. */
void
print_world(void)
{
	for (int j = 0; j < WIDTH; j++) {
		if (world[j])
			printf("x");
		else
			printf("_");
	}
	sleep(1);
	fflush(stdout);
	printf("\r");
}

int
main(void)
{
	/* Simulate life in 1-D. */
	for (int i = 0; i < MAXITER; i++) {
		print_world();
		for (int j = 0; j < WIDTH; j++) {
			int m[3] = { get(world, WIDTH, j - 1),
				     get(world, WIDTH, j),
				     get(world, WIDTH, j + 1) };
			next[j] = values[getval(m)];
		}
		memcpy(world, next, sizeof (world));
	}
}
