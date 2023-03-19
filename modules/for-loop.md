# The `for` loop

Formally defined as:

```
for (<init>; <predicate>; <update>)
	<body>
```

It is the same as:

```
<init>
while (<predicate>) {
	<body>
	<update>
}
```

Using the for loop is very often easier and more readable.

Example:
```C
int i;
for (i = 0; i < 10; ++i) {
	printf("%d\n", i);
}
```

Or in C99:

```C
for (int i = 0; i < 10; ++i) {
	printf("%d\n", i);
}
```

- the `break` statement terminates execution of the loop (i.e. it jumps right
  **after** the enclosing `}`)

- with the `continue` statement, the execution jumps to the end of the loop body
  (i.e. it jumps **at** the enclosing `}`) but the `<update>` part is executed.
  The execution then continues with the `<predicate>` test.  Example:

```
for (int i = 0; i < 3; ++i) {
	printf("%d\n", i);
	continue;
	putchar('a');
}

$ ./a.out
0
1
2
$
```

- both `break` and `continue` statements relate to the innermost loop
  they are executed in.

#source for.c

:wrench: print a subset of an ASCII table for characters `a` to `z`:

```
$ ./a.out
Dec	Oct	Char
97	141	a
98	142	b
99	143	c
100	144	d
101	145	e
...
...
```

#solution print-ascii-table-subset.c

:wrench: task: compute minimum of averages of lines in 2-D integer array (of
arbitrary dimensions) that have positive values (if there is negative value in
given line, do not use the line for computation).

#solution 2darray-min-avg.c
