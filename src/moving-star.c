/*
 * Implement a moving star that zick zacks on the __SAME__ line between some
 * boundary (say 50 character wide).
 *
 * This was an assignment after the __first__ C language seminar class in Feb
 * 2018.  After that intro class, students knew how to:
 *
 *	- declare variables of type int and float
 *	- do basic arithmetics
 *	- do a "while" loop
 *	- use an "if" (but __NOT__ "else")
 *	- use printf()
 *	- use a character '\r' to return to the beginning of a line
 *	- to use "poll(NULL, 0, <ms>)" to sleep <ms> miliseconds
 *
 * One thing I forgot to tell them was that they needed "fflush(stdout)" after
 * the line was printed.  As STDOUT is buffered, the text will generally not be
 * printed until a new line is printed, which is never the case here.
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
