/*
 * Implement a moving star that zick zacks on the same line between some
 * boundary (say 50 character wide).
 *
 * This is an assignment after the first C language seminar class.  Do not use
 * arrays or else branch; just print each character one by one via printf.
 *
 * See the assignment for important information that may help you in
 * implementing this:
 *
 * https://github.com/devnull-cz/c-prog-lang/blob/master/modules/moving-star.md
 */
#include <stdio.h>
#include <poll.h>

int
main(void)
{
	int i, j;
	int width = 50;
	/* Current position of the star on the line. */
	int pos = 0;
	/* Left to right (1) or right to left (-1). */
	int direction = 1;

	while (1) {
		j = 0;
		while (j < width) {
			i = 0;
			while (i < width) {
				if (i == pos)
					fprintf(stderr, "*");
				if (i != pos)
					fprintf(stderr, " ");
				++i;
			}
			fflush(stdout);
			poll(NULL, 0, 50);
			fprintf(stderr, "\r");
			pos = pos + direction;
			++j;
		}
		/*
		 * Remember, you are not supposed to use the "else" branch yet!
		 */
		direction = direction * -1;
		/*
		 * Move the position back within the boundary (ie. 'pos' here
		 * was either 'width' or -1 so it would never be printed again).
		 */
		pos = pos + direction;
	}
}
