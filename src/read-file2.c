#include <stdio.h>
#include <stdlib.h>
#include <err.h>

int
main(void)
{
	char a[16];
	FILE *fp;

	/* Choose any other file you have on your system. */
	if ((fp = fopen("/etc/passwd", "r")) == NULL)
		err(1, "fopen");

	/*
	 * fread() returns a number of *items* read (3rd argument).  If our item
	 * is not a single char but an array, it will either read the full item
	 * or not.  So, what happens if our file size is not divisible by 16
	 * without a reminder?
	 */
	while (fread(a, sizeof (a), 1, fp) == 1) {
		for (int i = 0; i < sizeof (a); ++i)
			putchar(a[i]);
	}

#if 0
	/* Note that we swapped the 2nd and 3rd arguments. */
	while (fread(a, 1, sizeof (a), fp) > 0) {
		/*
		 * Process the characters here, note that fread() may return
		 * less than sizeof (a).  You can again putchar() the characters
		 * read one by one.
		 *
		 * This solution can always print the whole file.
		 */
	}
#endif

	fclose(fp);
}
