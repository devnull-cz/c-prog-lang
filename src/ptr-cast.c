int
main(void)
{
	int a = 5;
	int *pi = &a;
	char *s = "foo";

	/* Generates a warning, assigning a pointer to an incompatible type. */
	s = pi;
	/* No warning (doing this makes no sense though). */
	s = (char *)pi;
}
