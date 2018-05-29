int
main(void)
{
	int a[1];
	int aa[1];

	/* The compiler fails on both. */
	++a;
	a = aa;
}
