# `goto` statement

Any statement may be preceded by a prefix that declares an identifier as a label
name.  Labels by themselves do not alter the flow of control.

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

Use of `goto` in C is often frowned upon unless it is used to jump to an
error/clean-up section or break from structured code.
While even that use is questioned by some, large number of major projects (Linux
kernel code, OpenSSH, OpenSSL, etc.) use it that way.  We strongly believe such
use simplifies the code if done well.

Consider the following code **with conditionals that do not nest**.  It leads to
code duplication (or large amount of indentation to fix that):

```C
int
myfn(void)
{
	/* declarations ommited */

	if ((p = malloc(16)) == NULL)
		return (1);
	if ((p2 = malloc(16)) == NULL) {
		free(p);
		return (1);
	}
	if ((p3 = malloc(16)) == NULL) {
		free(p);
		free(p2);
		return (1);
	}
	if ((p4 = malloc(16)) == NULL) {
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
```

With the conservative use of `goto`, we can simplify the code as follows:

```C
int
myfn(void)
{
	/* declarations ommited */

	int ret = 1;

	if ((p = malloc(16)) == NULL)
		return (1);
	if ((p2 = malloc(16)) == NULL)
		goto err;
	if ((p3 = malloc(16)) == NULL)
		goto err2;
	if ((p4 = malloc(16)) == NULL)
		goto err3;
	/* etc... */

	/* Getting here means all went fine. */
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
```

The good thing is that you clean up at one common place at the end of the
function.  If there is something new that needs to be cleaned up after the code
is modified, you add it to the clean-up section.  In the former example, you
would have to check all error paths and modify those one by one.

**We support reasonable use of `goto` for the clean-up and structured code
breaks**.  If used wisely, it leads to cleaner code and saves lots of
indentation.  Also note that the `break` and `continue` statements are jumps as
well, and imagine how to structure your code without it.
