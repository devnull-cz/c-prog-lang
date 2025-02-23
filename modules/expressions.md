# Expressions

> An expression is a sequence of operators and operands that specifies computation of a
> value, or that designates an object or a function, or that generates side effects, or that
> performs a combination thereof.

- Every expression has a value.

- A logical expression has a value of either `0` or `1`, and its type is always
  an `int`.

```
1 > 10	... 0
10 > 1	... 1

printf("%d\n", 1 < 10);
--> 1
/* Yes, "equal to" in C is "==" as "=" is used for an assignment */
printf("%d\n", 100 == 101);
--> 0
```

- Even constants are expressions (more on that later), e.g. `1`.

- As the `while` statement is defined in C99 6.8.5 as follows:

```C
while (expression) statement
```

...and given that a constant is also an expression, a neverending `while` loop
can be written for example as follows.  It is because it will loop until the
expression becomes 0.  That is never happening in this case.

```
while (1) {
	...
}
```

You could also write `while (2)`, `while (1000)`, or `while (-1)`  and it would
still be a neverending loop but that is not how C programmers do it.

- Note that the `statement` from the spec definition can be a code block as you
  can see in the example code above, more on that later.
