/*
 * Reimplement fahr-to-cent.c using defines.
 */
#include <stdio.h>

#define	LOW		0
#define	HIGH		300
#define	F_TO_C_RATIO	(5 / 9.0)
#define	FAHR_72		72
#define	FAHR_32		32
#define	GAP		20

int
main(void)
{
	int low = LOW;
	int high = HIGH;
	int flag = 0;
	int i;

	while (low < high) {
		float cm;

		/* Insert my favorite temperature 72 */
		if (!flag && low > FAHR_72) {
			cm = (FAHR_72 - FAHR_32) * F_TO_C_RATIO;
			printf("%3d\t%6.2f\n", FAHR_72, cm);
			flag = 1;
			continue;
		}

		cm = (low - FAHR_32) * F_TO_C_RATIO;
		printf("%3d\t%6.2f\n", low, cm);
		low = low + GAP;
	}

	return (0);
}
