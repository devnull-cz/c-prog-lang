# Compound statement vs. expression:

- It is not allowed to have a compound statement within an expression.
  - That said, GCC has a language extension (gcc99) that can be used to allow
    this - the reason is for protecting multiple evaluation within macros.
  - The C99 standard does not define it.
  - gotcha: the following code has to be compiled with `gcc` with the
    `-pedantic-errors` option in order to reveal the problem

```
gcc -std=c99 -Wall -Wextra -pedantic-errors compound-statement-invalid.c

compound-statement-invalid.c: In function ‘main’:
compound-statement-invalid.c:8:6: error: ISO C forbids braced-groups within expressions [-Wpedantic]
    8 |  if (({ i *= 2; puts("doubled");}), i % 2 == 0) {
      |      ^
```

Our recommendation is to always use these options.

#source compound-statement-invalid.c
