# Ternary operator

```
    cond ? expr1 : expr 2
```
same as
```
    if (cond) expr else expr2
```    
e.g.
```
    max = (i > j) ? i : j;
```    
note that if we add a semicolon, an expression becomes a statement, e.g.:
```
      (i == j) ? i++ : j++;
```
will increment i or j. the parens are not needed but generally
used for better readability.

code: :eyes: [ternary-assign.c](src/ternary-assign.c)

---

:wrench: write an expression that returns maximum of 3 integers i,j,k using
ternary operator

  - do not use any macros

solution: [3max.c](src/3max.c)

## quiz

see the code in :eyes: [ternary.c](src/ternary.c)

  - is this possible to do with ternary operator ?
  - how would you fix it ?
  - the usual solution is to put this into macro. many libraries/programs
    define their own MAX/MIN macros.


