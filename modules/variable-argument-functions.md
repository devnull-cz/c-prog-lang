# Functions with variable number of arguments

- functions can have variable number of arguments of different types (more on
  that later)
    - the three dots is called *ellipsis*
```C
void func(fmt, ...);
```

- the first argument usually describes the rest of arguments in some way
  - usually it is a format string.  It could possibly be an argument count if
    they were of the same type however in that case they would probably be
    passed as an pointer (we will get to pointers in a later class).


:wrench: write a function that takes variable number of `ULL` arguments
  and returns their sum

- use the stdarg(3) man page
- what happens if there is one `int` value passed in between the `ULL`
  arguments ?

#solution stdarg.c
