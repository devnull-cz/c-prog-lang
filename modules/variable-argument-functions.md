# Functions with variable number of arguments

- Functions can have variable number of arguments of different types (more on
  that later).
	- It must have at least one fixed argument (or more), and the rest is
	  denoted with three dots `...`
	- The dots are called *ellipsis*
```C
int printf(fmt, ...);
```

- The first argument typically describes the rest of arguments in some way
	- Usually it is a format string as in `printf`.  It could possibly be an
	  argument count if those were of the same type however in that case
	  they would probably be passed as an pointer (we will get to pointers
	  in a later class).

:wrench: write a function that takes variable number of `ULL` arguments and
returns their sum

- Use the stdarg(3) man page.
- What happens if there is one `int` value passed in between the `ULL`
  arguments?

#solution stdarg.c
