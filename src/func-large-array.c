/*
 * Usually it is not wise to define large arrays inside a function, especially
 * if it is recursive or called in multi-threaded environment (where stack
 * size can be limited).
 *
 * To make sure this does not happen (outside of specified boundary), use
 * compiler check, e.g. for GCC:
 *
 *   gcc -Wframe-larger-than=32768 -Wall -Wextra ...
 */

int
foo(int n)
{
	int a[8192 * 1000] = { 0 };

	// To prevent the code from being optimized away.
	a[0] = n;

	return a[0];
}

int
main(void)
{
	foo(4);
}
