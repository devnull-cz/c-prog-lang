# the "for" loop

formally defined:
```
	for (<init>; <predicate>; <update>)
		<body>
```

  - it is the same as:

```
	<init>
	while (<predicate>) {
		<body>
		<update>
	}
```
  - Using the for loop is very often easier and more readable.

  Example:
```C
	int i;
	for (i = 0; i < 10; ++i)
		printf("%d\n", i);
```

  - or in C99:

```C
	for (int i = 0; i < 10; ++i)
		printf("%d\n", i);
```

  - if `break` jump statement happens in the body, the control is transferred to
    the end of the loop without executing the `<update>` part.
  - with `continue` jump statement, the rest of the body is skipped.
    The `<update>` part is then performed for the `for` loop but not for the
    `while` loop.
  - both `break` and `continue` statements relate to the loop they are executed in

:eyes: code: [for.c](/src/for.c)

:wrench: task: compute minimum of averages of lines in 2-D integer array (of
arbitrary dimensions) that have positive values.

   :eyes: code: [2darray-min-avg.c](/src/2darray-min-avg.c)
