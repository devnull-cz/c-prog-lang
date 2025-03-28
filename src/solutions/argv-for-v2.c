#include <stdio.h>

int
main(int argc, char **argv)
{
	(void)argc;

	/* Not a nice way of doing things but shown as possible. */
	for ( ; *argv != NULL; printf("'%s'\n", *argv++))
		;
}
