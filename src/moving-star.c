/*
 * Implement a moving star that zick zacks on the same line between some
 * boundary (say 50 character wide).
 *
 * This is an assignment after the first C language seminar class.
 *
 * See the assignment for important information that may help you in
 * implementing this:
 *
 * https://github.com/devnull-cz/c-prog-lang/blob/master/modules/moving-star.md
 */
#include <stdio.h>
#include <poll.h>

#define	WIDTH	50

int
main(void)
{
	int i, j;
	/* Current position of the star on the line. */
	int pos = 0;
	/* Left to right (1) or right to left (-1). */
	int direction = 1;

	while (1) {
		j = 0;
		while (j < WIDTH) {
			i = 0;
			while (i < WIDTH) {
				if (i == pos)
					fprintf(stderr, "*");
				if (i != pos)
					fprintf(stderr, " ");
				++i;
			}
			fflush(stdout);
			poll(NULL, 0, 30);
			fprintf(stderr, "\r");
			pos = pos + direction;
			++j;
		}
		/*
		 * Remember, you do not know how to use the "else" branch yet.
		 */
		direction = direction + 2;
		if (direction == 3)
			direction = -1;
		/*
		 * Move the position back within the boundary (ie. pos here was
		 * either WIDTH or -1 so it would never be printed again).
		 */
		pos = pos + direction;
	}
}
