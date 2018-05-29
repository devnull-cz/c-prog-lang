int
main(void)
{
	int a = 5;
	int *pi = &a;
	char *s = "foo";

	/* generates a warning, assigning a pointer to an incompatible type */
	s = pi;
	/* no warning */
	s = (char *)pi;

	return (0);
}
