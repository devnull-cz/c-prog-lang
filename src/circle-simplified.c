#include <math.h>
#include <stdio.h>
#include <string.h>

#define	MYRAD	10

char a[2 * MYRAD + 1][2 * MYRAD + 2];

int
main(void)
{
	memset(a, ' ', (2 * MYRAD + 1) * (2 * MYRAD + 2));

	for (int i = -MYRAD; i <= MYRAD; ++i) {
		int y = sqrt(MYRAD * MYRAD - i * i);

		a[i + MYRAD][y + MYRAD] = '*';
		a[i + MYRAD][-y + MYRAD] = '*';
		a[i + MYRAD][2 * MYRAD + 1] = '\0';
		printf("%s\n", a[i + MYRAD]);
	}
}
