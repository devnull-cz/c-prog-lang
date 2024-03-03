#include <stdio.h>
#include <ctype.h>	// isspace()

int
main(void)
{
	int c;
	int cnt = 0;
	int word = 0;

	while ((c = getchar()) != EOF) {
		/* Use library function (hence the ctype.h include above) */
		if (isspace(c)) {
			if (word == 1) {
				cnt++;
				word = 0;
			}
		} else {
			word = 1;
		}
	}

	/* No newline at the end of input. */
	if (word)
		++cnt;

	printf("cnt = %d\n", cnt);
}
