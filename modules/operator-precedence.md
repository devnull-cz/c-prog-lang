# Operator precedence

There are 15 levels of operator precedence,
see the table at http://en.cppreference.com/w/c/language/operator_precedence

## Associativity

If there are multiple operators with the same precedence in an expression,
the evaluation is decided based on their associativity.

For example:
```C
8 / 2 % 3
```
has 2 operators with precedence level of 3 that have left-to-right
associativity. Therefore, they will be evaluated as
```C
(8 / 2) % 3
```
## Examples

`*p++` is `*(p++)` as suffix `++` is of higher priority than `*`.  However, the
value of the expression is still `*p` though as the dereference operator is
applied on `p` since that is the value of `p++`.

Note that suffix `++` and `--` has higher priority than prefix `++` and `--`,
and also has different associativity.

:wrench: Task: determine the outcome of these expressions/declarations:
  - `*p++`
  - `++*p`
  - `int *p[2]`
  - `int (*p)[3]`

## Operand evaluation order

Consider the following:

```C
int foo(void);
int bar(void);

int x = foo() + bar();
```

Note that the order of evaluation of subexpressions is an unspecified behavior
(see C99 6.5, paragraph 3).  So, `foo()` can be called before or after `bar()`.
If we add another function:

```C
int foo(void);
int bar(void);
int another(void);

int x = foo() + bar() + another();
```

then the expression will become `(foo() + bar()) + another()` however the order
in which `foo()` and `bar()` will be called is still undefined.

## Common gotchas

### `==` or `!=` versus `=`

the condition in the statement:
```C
if ((c = getchar()) != 0)
    ...
```

needs to be bracketed this way because `==` and `!=` is of higher precedence
than `=`.

### `&` or `*` versus `->` or `.`

`->` and `.` (structure member access) have higher precedence than `&` (address
of) and `*` (dereference)

# :wrench: Operator precedence and structures

consider the following structures:

```C
struct bar {
	int val;
} bar;

struct {
	int a[42];
	char *b;
	struct bar *c;
} foo;
```

Now initialize the members of `foo` with `1, 2, 3`, `"BBB"` and address of
`bar`, respectively and `val` in `bar` with `42`.  Use designated initializers.

write these expressions to get:
  - the address of `a`
  - the address of `b`
  - the address of the second element of `a`
  - the address of the 3rd character from string `b`
  - the 3rd character from string `b`
  - value of `val` in `bar` using `foo`
  - address of `val` in `bar` using `foo`

Use as few brackets as possible.

#solution struct-op-precedence.c
