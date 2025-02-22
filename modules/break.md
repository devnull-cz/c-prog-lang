# The `break` statement

- The `break` statement will cause a jump out of a most inner `while` loop (well,
  any kind of loop but we only introduced the `while` loop so far).

```
int finished = 0;
while (1) {
	if (finished)
		break;
	/* not finished work done here */
	call_a_function();
	k = xxx;
	...
	if (yyy) {
		...
		finished = 1;
	}
	/* more work done here */
	...
}
```

- There is no `break <level>` to say how many levels to break as might be found
  e.g. in a unix shell.
