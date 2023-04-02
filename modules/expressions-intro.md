# Expressions

> "In mathematics, an expression or mathematical expression is a finite
combination of symbols that is well-formed according to rules that depend on
the context."

In C99, section 6.5 expressions:

>"An expression is a sequence of operators and operands that specifies
computation of a value, or that designates an object or a function, or that
generates side effects, or that performs a combination thereof."

In C, expressions are, amongst others:

- identifiers
- constants
- string literals
- expressions in parentheses
- arithmetic expressions
- relational expressions
- function calls
- `sizeof`
- assignments
- ternary expressions

http://en.cppreference.com/w/c/language/expressions

In C99, an expression can produce results (`2 + 2` gets `4`) or generate
#module side-effect.md side effects
(e.g. upon evaluation, an expression `printf("foo")` sends a string literal to
the standard output as a side effect).

#source expression-statement.c

:wrench: Make the warning an error with your choice of compiler (would be a
variant of `-W` in GCC)
