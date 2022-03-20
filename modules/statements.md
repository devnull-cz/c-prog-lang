# Statements

Statements are (list not complete), expressions, selections (`if`, `switch` (not
introduced yet)), `{}` blocks (known as *compounds*), iterations, and jumps
(`goto` (not introduced yet), `continue`, `break`, `return`).

http://en.cppreference.com/w/c/language/statements

Basically, statements are pieces of code executed in sequence. The function body
is a compound statement. The compound statement (a.k.a. *block*) is a sequence
of statements and declarations.  Blocks can be nested.  Blocks inside a function
body are good for variable reuse.

A semicolon is not used after a compound statement but it is allowed.  The
following is valid code then:

```C
int
main(void)
{
	{ }
	{ };
}
```

**A declaration is not a statement** (there are subtle consequences, we can show
them later).

Some statements must end with `;`.  For example, expression statements.  The
following are all valid expression statements.  They do not make much sense
though and may generate a warning about an unused result.

```C
/* this one is not a statement */
char c;

/* these are all expression statements */
c;
1 + 1;
1000;
"hello";
```

#source null-statement.c
#source compound-statement.c

## w.r.t. compound statement vs. expression:

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
