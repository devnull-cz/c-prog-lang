# `goto` statement

Any statement may be preceded by a prefix that declares an identifier as a label
name.  Labels by themself do not alter the flow of control.

Within the same function, you can jump to a label via the *goto* statement.

```C
int
main(int argc, char **argv)
{
	if (argc == 1)
		goto err;
	/* Process arguments here. */
	return (0);
err:
	errx(1, "missing arguments");
	return (1);
}
```

In general, use of `goto` in C is generally frown upon unless it is used to jump
to an error/clean-up section.  Even that is questioned by many but large number
of major projects (Linux kernel code, OpenSSH, OpenSSL, etc.) use it that way.
Consider the following code **with conditionals that do not nest**.  It leads to
code duplication (or large amount of indentation to fix that):

```C
int
myfn(void)
{
	/* declarations */

	if ((p = malloc(16)) == NULL)
		return (1);
	if ((p2 = malloc(16) == NULL) {
		free(p);
		return (1);
	}
	if ((p3 = malloc(16) == NULL) {
		free(p);
		free(p2);
		return (1);
	}
	if ((p4 = malloc(16) == NULL) {
		free(p);
		free(p2);
		free(p3);
		return (1);
	}
	/* etc... */

	printf("Success.\n");
	free(p);
	free(p2);
	free(p3);
	free(p4);
	/* ... */
	return (0);
}

With the conservative use of `goto`, we can simplify the code as follows:

```C
int
myfn(void)
{
	/* declarations */
	int ret = 1;

	if ((p = malloc(16)) == NULL)
		return (1);
	if ((p2 = malloc(16) == NULL)
		goto err;
	if ((p3 = malloc(16) == NULL)
		goto err2;
	if ((p4 = malloc(16) == NULL)
		goto err3;
	/* etc... */

	/* If I got here, it means all went fine. */
	ret = 0;
	printf("Success.\n");

	free(p4);
err3:
	free(p3);
err2:
	free(p2);
err:
	free(p);
	return (ret);
}

The good thing is that you clean up at one common place, at the end of the
function.  If there is something new that needs to be cleaned up after the code
is enhanced, you just add it to the clean-up section.  In the former example,
you would have to check all error paths and modify those one by one.

We definitely support reasonable use of `goto` for the clean-up.  If used
wisely it leads to cleaner code and saves lots of intentation.  Also note that
the `break` statement is a jump as well, and imagine how to structure your code
without it.

Also note that "any statement may be **preceded** by... a label".  As `case` is
a label as well (only valid within the `switch` statement though), you cannot
have a declaration right after the `case` label.  You also cannot have a label
right before a closing `}`.  So, a *null statement* to the rescue:

```C
switch (c) {
case 'a':
	;	/* must be here as a declaration is not a statement. */
	int a;
	/* ... */
default:
	;	/* must be here as the closing '}' is not a statement. */
}
```
