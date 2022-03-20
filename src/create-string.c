/*
 * See ../modules/warm-up/string.md
 */
#include <stdio.h>

char str[] = { 'h', 'e', 'l', 'l', 'o', '\n', 'w', 'o', 'r', 'l', 'd', '\n',
    '\t', '\170', '\n', '\'' };

int
main(void)
{
	printf("%s\n", str);
}
