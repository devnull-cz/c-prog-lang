/*
 * A very simple moutain generator.  At every point you go horizontal, up, or
 * down.  The program generates something like the following:
 *
 * $ a.out
 *
 *                /                         /--
 *             / / \- /--                  /   \                       / /-
 *            / \    \   \              /--     \-                   /- \  \
 *           /            \            /          \             /-- /       \
 *       / /-              \-  /--   /-            \-          /   \         \
 *      / \                  \-   \ /                \-  /-- /-
 *     /                           \                   \-   \
 *  /--
 * -
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define	WIDTH	80
#define	HEIGHT	30

char mnt_chars[3] = "\\-/";

void
print_2D_array(size_t width, size_t height, char array[][width])
{
	// Print the 2-D array to standard output.
	int h = height - 1;

	while (h >= 0) {
		int i = 0;
		while (i < width) {
			printf("%c", array[h][i]);
			++i;
		}
		printf("\n");

		--h;
	}
}

int
get_rand(int h, int max)
{
	int r;

	while (1) {
		// Get -1, 0, or 1
		r = rand() % 3 - 1;

		// Reached the bottom, retry.
		if (h == 0 && r == -1)
			continue;

		// Reached the top, retry.
		if (h == max - 1 && r == 1)
			continue;

		break;
	}

	return (r);
}

void
mountain(size_t width, size_t height, char array[][width])
{
	int i = 0, h = 0;

	while (i < width) {
		int r;

		r = get_rand(h, height);
		h += r;
		array[h][i] = mnt_chars[r + 1];
		i++;
	}

	print_2D_array(width, height, array);
}

int
main(int argc, char *argv[])
{
	char array[HEIGHT][WIDTH];

#ifdef HAVE_SRANDDEV
	sranddev();
#else
	srand(time(NULL));
#endif
	memset(array, ' ', HEIGHT * WIDTH);

	int limit = 1;
	if (argc > 1)
		limit = atoi(argv[1]);

	/* Make them overlaid for a better visual effect. */
	int i = 0;
	while (i < limit) {
		mountain(
		    sizeof (array[0]) / sizeof (array[0][0]),
		    sizeof (array) / sizeof (array[0]),
		    array);
		i++;
	}

	return (0);
}
