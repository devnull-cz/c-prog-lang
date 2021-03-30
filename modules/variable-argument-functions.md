# Functions with variable number of arguments

- functions can have variable number of arguments of different types (more on
  that later)
    - it must have at least one fixed argument (or more), and the rest is
      denoted with three dots `...`
    - the dots are called *ellipsis*
```C
int printf(fmt, ...);
```

- the first argument typically describes the rest of arguments in some way
  - usually it is a format string as in `printf`.  It could possibly be an
    argument count if those were of the same type however in that case they would
    probably be passed as an pointer (we will get to pointers in a later class).

:wrench: write a function that takes variable number of `ULL` arguments and
returns their sum

- use the stdarg(3) man page
- what happens if there is one `int` value passed in between the `ULL`
  arguments ?

#solution stdarg.c
