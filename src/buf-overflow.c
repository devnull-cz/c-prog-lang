#include <string.h>

int
main(void)
{
	char foo[4];
	char bar[5];

	/* BUG: will always overflow destination buffer! */
	strncpy(foo, bar, sizeof (bar));
}
