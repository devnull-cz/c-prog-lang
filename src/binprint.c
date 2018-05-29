#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

void
binprint(int n)
{
	char a[sizeof (int) * 8];
	int i = 1;

	assert(n >= 0);
	(void) memset(a, '0', sizeof (a));
	a[sizeof (a) - 1] = '\0';

	while (n > 0) {
		if (n % 2 == 1)
			a[sizeof (a) - i - 1] = '1';
		if ((n = n / 2) > 0)
			++i;
	}
	printf("%s\n", a + sizeof (a) - i - 1);
}
