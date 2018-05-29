#include <stdio.h>

int
main(void)
{
again:
	{
		static int i = 0;

		if (i == 3)
			return (0);

		++i;
		printf("%d\n", i);
	}

	goto again;
}
