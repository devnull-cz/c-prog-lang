# Operator precedence

There are 15 levels of operator precedence,
see the table on http://en.cppreference.com/w/c/language/operator_precedence

## Examples

`*p++` is `*(p++)` as `++` is of higher priority than `*`.  However, the value of the expression
is still `*p` though as `p` is incremented after the expression is evaluated.

:wrench: Task: determine the outcome of these expressions/declarations:
  - `*p++`
  - `++*p`
  - `int *p[2]`
  - `int (*p)[3]`

## Associativity

If there are multiple operators with the same precedence in an expression,
the evaluation is decided based on associativity.

For example:
```C
8 / 2 % 3
```
has 2 operators with precedence level of 3 that have left-to-right
associativity. Therefore, they will be evaluated as
```C
(8 / 2) % 3
```

## Operand evaluation order

Consider the following:

```C
int foo(void);
int bar(void);

int x = foo() + bar();
```

The standard does not say how the evaluation will be done. `foo()` can be called
before or after `bar()`. If we add another function:

```C
int foo(void);
int bar(void);
int another(void);

int x = foo() + bar() + another();
```

then the expression will become `(foo() + bar()) + another()` however the order
in which `foo()` and `bar()` will be called is still undefined.

## Common gotchas

### `==` versus `=`/`!=`

the condition in the statement:
```C
if ((c = getchar()) != 0)
    ...
```

needs to be bracketed this way because `=`/`!=` has higher precedence than `=`.

### `&` or `*` versus `->` or `.`

`->` and `.` (structure member access) have higher precedence than `&` (address
of) or `*` (dereference)

:wrench: condsider structure
```C
struct {
	int a[42];
	char *b;
} foo;
```
initialize it with `1, 2, 3` and `"BBB"`, respectively.

write these expressions:
  - get the address of the second item of `a`
  - get the 3rd character from string `b`
  - get the address of the 3rd character from string `b`

solution: #source struct-op-precedence.c
