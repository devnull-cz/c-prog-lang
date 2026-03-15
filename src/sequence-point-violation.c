/*
 * Example on sequence point violations.
 *
 * See C99, 6.5 Expressions, paragraph 2, for more information.
 *
 * See a summary of the sequence points in C99 Annex C.
 */
int
main(void)
{
	int a = 0;
	int b[10];

	/*
	 * This is a sequence point violation as "an object may have its value
	 * modified at most once between sequence points".  Here we try to
	 * modify it twice.
	 *
	 * The previous sequence point was the end of the array declarator
	 * above (6.7.5), and the next sequence point is the end of the
	 * expression statement (6.8.3).
	 */
	a = a++;

	/*
	 * Another sequence point violation.  This one relates to the second
	 * sentence in paragraph 2: "Furthermore, the prior value shall be read
	 * only to determine the value to be stored".
	 *
	 * Note that the previous sequence point was the end of the assignment
	 * above, the next sequence point is the end of the assignment below.
	 *
	 * That means that iff the object is modified in between two sequence
	 * points, reading its value must be used to compute the resulting (new)
	 * value.  The use of 'a' as an index violates that rule -> 'a' is read
	 * but NOT to compute the a's new value.
	 */
	b[a] = a++;

	return (b[a]);
}
