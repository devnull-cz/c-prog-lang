# Statements

Statements are (only from what we already learned), expressions, selections
("if", "switch" (not introduced yet)), {} blocks (known as *compounds*),
iterations, and jumps ("goto" (not introduced yet), "continue", "break",
"return").

  http://en.cppreference.com/w/c/language/statements

Basically, statements are pieces of code executed in sequence. The function body
is a compound statement. The compound statement (a.k.a. *block*) is a sequence
of statements and declarations. Blocks can be nested. Blocks inside function
body are good for variable reuse.

Semicolon is not used after a compound but it is allowed.

**A declaration is not a statement** (there are subtle consequences, we can show
them later).

Some statements must end with `;`.  For example, expression statements.  The
following are all valid statements.  They do not make much sense though and will
probably generate a warning about an unused result.

```C
	char c;

	c;
	1 + 1;
	1000;
	"hello";
```

:eyes: code: [null-statement.c](/src/null-statement.c),
[compound-statement.c](/src/compound-statement.c)

## w.r.t. compound statement vs. expression:

 - it is not allowed to have compound statement within expression
   - that said, GCC has a language extension (gcc99) that can be used to allow
     this - the reason is for protecting multiple evaluation within macros
   - the C99 standard does not define this, therefore it's not there

- gotcha: the code has to be compiled with gcc with the -pedantic-errors
  	  option in order to reveal the problem

```
  gcc -std=c99 -Wall -Wextra -pedantic-errors compound-statement-invalid.c
```

  - our recommendation is to always use these options

:eyes: code: [compound-statement-invalid.c](/src/compound-statement-invalid.c)
