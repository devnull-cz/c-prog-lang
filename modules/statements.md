# Statements

Statements are (list not complete): expressions, selections (`if`, `switch` (not
introduced yet)), `{}` blocks (known as *compounds*), iterations (`while`,
`for`), and jumps (`goto` (not introduced yet), `continue`, `break`, `return`).

http://en.cppreference.com/w/c/language/statements

Basically, statements are pieces of code executed in sequence. The function body
is a compound statement. The compound statement (a.k.a. *block*) is a sequence
of statements and declarations.  Blocks can be nested.  Blocks inside a function
body can be used for variable reuse but should be used for that with care, if at
all.

A semicolon is not used after a compound statement but it is allowed.  The
following is valid code then, and does essentially nothing:

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

#source null-statement.c
#source compound-statement.c

Some statements must end with `;`.  For example, expression statements.  The
following are all valid expression statements.  They do not make much sense
though and may generate a warning about an unused result in some compilers.

```C
/* this one is not a statement */
char c;

/* these are all expression statements */
c;
1 + 1;
1000;
"hello";
```

#source expression-statement.c

:wrench: Make the warning an error with your choice of compiler (would be a
variant of `-W` in GCC)
