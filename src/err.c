#include <err.h>
#include <errno.h>

int
main(void)
{
	errno = 3;
	if (errno)
		err(1, "ERROR: ");
}
