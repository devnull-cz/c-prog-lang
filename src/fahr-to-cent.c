#include <stdio.h>

int
main(void)
{
	int low = 0;
	int high = 300;
	int flag = 0;
	int i;

	while (low < high) {
		float cm;
		int f72 = 72;
#if 0
		/* When we know "if", insert my favorite temperature 72 */
		if (!flag && low > f72) {
			cm = 5 * (f72 - 32) / 9.0;
			printf("%3d\t%6.2f\n", f72, cm);
			flag = 1;
			continue;
		}
#endif

		cm = 5 * (low - 32) / 9.0;
#if 0
		/* this still results in integer, need 9.0 */
		cm = 5 * (low - 32) / 9;
#endif
		printf("%3d\t%6.2f\n", low, cm);
		low = low + 20;
	}

	return (0);
}
