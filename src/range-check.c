#include <stdio.h>
#include <err.h>
#include <stdbool.h>

bool
check(long off, size_t size, size_t limit)
{
	// The last portion of the check is overflow avoidance.
	if (off < 0 || off > limit || size > limit || limit - off < size) {
		warnx("not valid input");
		return (false);
	}
	
	return (true);
}

int
main(void)
{
	printf("%d\n", check(-1, 1, 255));

	return (0);
}
