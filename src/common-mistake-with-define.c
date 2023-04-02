/*
 * Run "gcc -E" on this code.
 *
 * This code will NOT compile.  It is for demonstration purpose only.
 */

#define MYDEF = 3

int
main(void)
{
	int i;

	if (i < MYDEF) {
		// ...
		;
	}       

	/*
	 * The following will not generate "<=" but fortunately a space will be
	 * inserted after '<', generating a syntax error again.
	 */
	if (i <MYDEF) {
		// ...
		;
	}       
}
