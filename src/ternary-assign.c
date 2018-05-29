int
main(void)
{
	int i, j, max;

	/*
	 * Note: the ternary conditional ?: has higher precedence than simple
	 * 	 assignment. If not using parens, it would try to assigng the
	 *	 expression '(i > j) ? max = i : max' to j.
	 */

	// (i > j) ? max = i : max = j;
	// (i > j) ? (max = i) : max = j;
	(i > j) ? (max = i) : (max = j);

	return (0);
}
