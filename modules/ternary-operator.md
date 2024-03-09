# Ternary operator

```
cond ? expr1 : expr 2
```

Is the same as:

```
if (cond) expr else expr2
```

Example:

```
max = (i > j) ? i : j;
```

Note that if we add a semicolon, an expression becomes a statement, e.g.:

```
(i == j) ? i++ : j++;
```

That will increment `i` or `j`.  The parentheses are not needed but generally
used for better readability.

code: #source ternary-assign.c

## :wrench: `toupper()` using ternary operator

Rewrite the
#module home-assignments/toupper.md convert small characters to upper case
program from last time using a function that utilizes the ternary operator
(single line of code)

#solution toupper-ternary.c

## :wrench: Min/max of 3 integer values

Write an expression that returns maximum of 3 integers `i`, `j`, `k` using
ternary operator.  Do not use any macros (in case you know those).

#solution 3max.c
