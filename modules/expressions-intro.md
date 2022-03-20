# Expressions

> "In mathematics, an expression or mathematical expression is a finite
combination of symbols that is well-formed according to rules that depend on
the context."

In C, expressions are, amongst others, variables, constants, strings, and
expressions in parentheses.  Also arithmetic expressions, relational
expressions, function calls, `sizeof`, assignments, and ternary expressions.

http://en.cppreference.com/w/c/language/expressions

In C99, an expression can produce results (`2 + 2` gets `4`) or generate side effects
(`printf("foo")` sends a string literal to the standard output).

#source expression-statement.c

:wrench: task: make the warning an error with your choice of compiler (would be
a variant of `-W` in GCC)
