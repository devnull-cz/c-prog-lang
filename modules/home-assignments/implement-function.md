## Implement a function

Write a function that copies a string to a character array.  It returns the
number of characters copied.

Note that **a string constant is read-only by definition**, and writing to it is
an undefined behavior.  That is:

```
char *s = "hello"
// Do not do this.  Different compilers may act differently.
s[0] = 'H';
```

Take
#source implement-function.c
and implement the function, see the comment inside.

Verify the code prints exactly what it says in the comments.  `gcc -Wall -Wextra
implement-function.c` **must** be clear of any warnings.

Solution:
#source implement-function-solution.c
