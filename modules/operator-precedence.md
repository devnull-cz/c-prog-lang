# Operator precedence

`*p++` is `*(p++)` as `++` is of higher priority than `*`.  However, the value of the expression
is still `*p` though as `p` is incremented after the expression is evaluated.

:wrench: Task: determine the outcome of these expressions/declarations:
  - `*p++`
  - `++*p`
  - `int *p[2]`
  - `int (*p)[3]`

See the table on http://en.cppreference.com/w/c/language/operator_precedence

## gotcha: `==` versus `=`/`!=`

the condition in the statement:
```C
if ((c = getchar()) != 0)
    ...
```

needs to be bracketed this way because `=`/`!=` has higher precedence than `=`.
