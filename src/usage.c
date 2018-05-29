#include <stdio.h>
#include <err.h>

int
main(int argc, char *argv[])
{
	if ((argc != 3) && (argc != 2))
		errx(1, "usage: %s <arg1> [arg2]", argv[0]);

	return (0);
}
