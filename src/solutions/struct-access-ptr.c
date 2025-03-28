struct foo_s {
	int *a;
	char b;
};

int
main(void)
{
	struct foo_s foo;
	struct foo_s *p_foo = &foo;

	/* first dereference and then access */
	int i = 42;
	foo.a = &i;
	*(*p_foo).a = 1;	// eq. *(p_foo->a) = 1;
	(*p_foo).b = 'C';	// ditto
}
