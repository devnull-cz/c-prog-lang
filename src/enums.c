#include <stdio.h>

/*
 * As with structures, you may or may not use a comma after the last enumerator.
 */
enum white_space { NL = '\n', SP = ' ', TAB = '\t', };

int
main(void)
{
	printf("%d\n", SP);
	printf("'%c'\n", SP);

	return (0);
}
