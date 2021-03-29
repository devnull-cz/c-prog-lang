#include <err.h>

int
main(void)
{
	int some_error = 3;

	if (some_error)
		errx(1, "ERROR: %d", some_error);
}
