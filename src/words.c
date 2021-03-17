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
		if (!isspace(c))
			word = 1;
		else {
			if (word == 1) {
				cnt++;
				word = 0;
			}
		}
	}

	printf("cnt = %d\n", cnt);
}
