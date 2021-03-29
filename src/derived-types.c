/*
 * Type of "myarray" is "an array of 10 pointers to a pointer to char".  It is
 * called a derived type.
 */
typedef char **myarray[10];
myarray a;

int
main(void)
{
	char c;
	char *p = &c;

	/* OK */
	a[8] = &p;
	/* Assigning an incompatible pointer, your compiler should complain. */
	a[7] = p;
}
