#include <stdio.h>

int
main(void)
{
	char s[] = { 'f', 'o', 'o' };
	/*
	 * Note the continuation line.  Indent such a line by 4 characters
	 * instead of a tabulator.  Always stick to 80 columns.
	 */
	char s2[] = { 'f', 'o', 'o', 'f', 'o', 'o', 'f', 'o', 'o', 'f', 'o',
	    'o', 'f', 'o', 'o', 'f', 'o', 'o' };

	printf("%s\n", s);
	printf("%s\n", s2);

	return (0);
}
