#include <stdio.h>
#include <stdbool.h>

int
main(void)
{
	int c;
	char string1[] = "abcdefg";
	char string2[] = "XYZ#";

	while ((c = getchar()) != EOF) {
		bool found = false;
		size_t i;

		for (i = 0; i < sizeof (string1) - 1; ++i) {
			if (c == string1[i]) {
				found = true;
				break;
			}
		}

		if (found) {
			putchar(i > sizeof (string2) - 2 ?
			    string2[sizeof (string2) - 2] : string2[i]);
		} else {
			putchar(c);
		}
	}

	return (0);
}
