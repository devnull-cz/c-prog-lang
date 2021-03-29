#include <stdio.h>

int
main(void)
{
	int low = 0;
	int high = 300;
	int printed72 = 0;
	int i;

	while (low < high) {
		float cm;
		int f72 = 72;
#if 0
		/* When we know "if", insert my favorite temperature 72 */
		if (!printed72 && low > f72) {
			cm = 5 * (f72 - 32) / 9.0;
			printf("%3d\t%6.2f\n", f72, cm);
			printed72 = 1;
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
}
