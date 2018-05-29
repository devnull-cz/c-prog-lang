/*
 * Convert all input to upper characters.  Test with:
 *
 *	$ cat /etc/passwd | ./a.out
 */
#include <stdio.h>

int
main(void)
{
	int c;

	while (1) {
		c = getchar();

		if (c == EOF)
			break;

		if (c >= 'a' && c <= 'z')
			printf("%c", 'A' + c - 'a');
		else 
			printf("%c", c);
	}
}
