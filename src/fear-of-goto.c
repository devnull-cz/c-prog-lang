/*
 * As seen in the source of an UNIX operating system. The author chose not to
 * use goto however needed to jump out of block of code so he used do/while.
 */

#include <stdio.h>

int
main(void)
{
	do {

		printf("foo\n");

		break;

		printf("bar\n");

	} while (0);

	printf("finish\n");

	return (0);
}
