/*
 * Example on sequence point violations.
 *
 * See C99, 6.5 Expressions, paragraph 2, for more information.
 */
int
main(void)
{
	int a = 0;
	int b[10];

	/*
	 * This is a sequence point violation as an object may have its value
	 * modified at most once between sequence points.  Here we try to modify
	 * it twice.
	 */
	a = a++;

	/*
	 * Another sequence point violation.  This one relates to the second
	 * sentence in paragraph 2: "Furthermore, the prior value shall be read
	 * only to determine the value to be stored".  That means that if the
	 * object is read (used), it must be used to compute the resulting
	 * value.  The use of 'a' as an index below violates that rule.
	 */
	b[a] = a++;

	return (b[a]);
}
