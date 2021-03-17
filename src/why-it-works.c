/*
 * This code may actually "work" by accident and print 100.  Why is that?
 */

#include <stdio.h>

int
addnum(int n1, int n2)
{
	int n = n1 + n2;
}

int
main(void)
{
	printf("%d\n", addnum(1, 99));
}
