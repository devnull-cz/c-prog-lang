# Function arguments

Say, what happens if you put a `char` as an argument of a function that accepts
an `int`?  As you might expect, the byte is just assigned to an `int`.

In general, the expressions passed as arguments are evaluated first, then the
value of the resulted type is converted to the parameter type as in assignment.

More on that later.  For more information, see 6.9.1 in
[C99](/modules/c99-standard.md)

The order of evaluation of function arguments is unspecified, see 6.5.2.2p10
in [C99](/modules/c99-standard.md):

> The order of evaluation of the function designator, the actual arguments, and
> subexpressions within the actual arguments is unspecified, but there is a
> sequence point before the actual call.

That means, do not do things like these as it is not specified whether the 2nd
argument expression is evaluated after the first agument is processed, or
before.  So, based on the compiler you use, you may either call the function
with `(1, 2)` or `(2, 2)`.

```
int i = 1;

myfn(i, ++i);
```
