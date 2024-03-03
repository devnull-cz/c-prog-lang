# The comma operator

Useful to perform expression evaluations in one place. The first part is evaluated, then the second part.
The result of the expression is the result of the second part, e.g.:

```
while (a = 3, b < 10) {
...
}
```

The cycle will be controlled by the boolean result of the second expression.

This is not limited just to 2 expressions, you can add more comma operators.  It
is left associative.

Note that the comma used in a variable declaration (`int a, b = 3;`) or a
function call is not comma operator.

:wrench: What will be returned? #source comma.c

This is handy for cycle control expressions.
