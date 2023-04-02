/*
 * This is a simplified version of circle.c
 */
#include <math.h>
#include <stdio.h>
#include <string.h>

#define	MYRAD	15

int
main(void)
{
	char a[2 * MYRAD + 2];

	a[2 * MYRAD + 1] = '\0';
	for (int i = -MYRAD; i <= MYRAD; ++i) {
		int y = sqrt(MYRAD * MYRAD - i * i);

		memset(a, ' ', sizeof (a) - 1);
		a[y + MYRAD] = '*';
		a[-y + MYRAD] = '*';
		printf("%s\n", a);
	}
}
