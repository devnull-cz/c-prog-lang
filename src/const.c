int
main(void)
{
	const int a[3] = { 1, 2, 3 };
	int const b[3] = { 1, 2, 3 };

	/* The compiler prints an error for the next line. */
	a[0] = 4;
}
