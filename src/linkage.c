#include <stdio.h>

extern int i;
/*
 * This will generate an error as the 'si' object is only visible within the
 * ext.c file.
 */
extern int si;

int
main(void)
{
	printf("%d\n", i);
	printf("%d\n", si);
}
