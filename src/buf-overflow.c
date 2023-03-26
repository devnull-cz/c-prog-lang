#include <string.h>

int
main(void)
{
	char foo[4] = "foo";
	char bar[5] = "barr";

	/* BUG: will always overflow destination buffer! */
	strncpy(foo, bar, sizeof (bar));
}
