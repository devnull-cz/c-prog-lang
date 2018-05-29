/*
 *
 * Identifiers fall into several name spaces that do not interfere with one
 * another.
 *
 * These classes are: objects, functions, typedef constants; labels; tags of
 * structures or unions, and enumerations; and structure or union individually.
 *
 * The "individual" part means each structure or union has its own namespace.
 *
 * The following code compiles with no error nor warning.
 */

struct a {
	int a;
};

#if 0
/* This would clash with the struct above. */
enum a {
	BLUE,
}

/* This would clash with the function name below. */
int a;
#endif

void
a(void)
{
}

int
main(void)
{
	goto a;

a:
	return (0);
}
