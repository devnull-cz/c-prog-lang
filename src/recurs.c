#include <err.h>
#include <stdlib.h>
#include <unistd.h>

static void
foo(int n)
{
	if (n == 0)
		return;

	sleep(1);
	foo(--n);
}

int
main(int argc, char *argv[])
{
	if (argc != 2)
		errx(1, "usage: %s <num>", argv[0]);

	foo(atoi(argv[1]));

	return (0);
}
