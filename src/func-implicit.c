// gcc -std=c11 -pedantic-errors -Wall -Wextra

#include <stdbool.h>

// implicit function definitions should not be possible in C99+
bool
fce()
{
	return (1);
}

int
main(void)
{
	return (fce());
}
