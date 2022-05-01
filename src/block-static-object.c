#include <stdio.h>

int
main(void)
{
	/* There can be some code here. */
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
