/*
 * You can use argv as a 2-dimensional array but you must make sure the element
 * is there otherwise you are accessing memory you are not supposed to, and may
 * core dump.
 *
 *	 $ ./a.out whatever abcde
 *	 d
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>

int
main(int argc, char **argv)
{
	assert(argc > 2);
	assert(strlen(argv[2]) > 3);

	printf("%c\n", argv[2][3]);
	printf("%c\n", *(*(argv + 2) + 3));

	return (0);
}
