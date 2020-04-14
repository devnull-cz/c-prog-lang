# Memory leaks

The C runtime does not have a garbage collector so all heap allocated memory has
to be explicitly freed via `free`() after it is no longer needed.  If not freed,
that creates a resource leak called a *memory leak*.  Depending on the problem
this might cause the problem of running out of memory later on (and then
`malloc`/`calloc` can start returning `NULL`).

The leaks can be checked using static or dynamic analyzers.

:wrench: write a program that takes all arguments that follow `argv[0]`,
concatenates them (without the terminating `NUL` character) into one string
dynamically allocated via `malloc`() and prints this string to the standard
output.

  - the concatenation can be done either by hand (try that first) or strncat()
    (try that afterwards)

#source argv-concat.c

You can then put the string processing in a loop and comment out the `free`()
call on the allocated memory.  Then check out with `top` that the memory size of
the running program quickly increases.
