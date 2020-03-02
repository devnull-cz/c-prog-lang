# The `break` statement

- statement `break` will cause a jump out of a most inner while loop (well, any
  loop but we only introduced the `while` loop so far).

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
