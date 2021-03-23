# Arithmetic type conversions

In (very) general, if *binary* operators have operands of different types, the
"lower" is promoted to "upper".  Eg. if one operand is a `long double`
and the other is not, the other operand is promoted to a `long double`.

What is more, in most operations (for every operator, the spec says what is
done in this respect), `char` and `short` int operands are converted to `int`s,
and to `unsigned int`s if they do not fit in an `int`.  That conversion is
called *integer promotion*.  This is done to make the language runtime fast (on
x86 32-bit arithmetics can be much faster than when using 16-bit operands).

*Most operations* means all binary operators.  A ternary operator as well.  And
even some unary operators.

`sizeof (1)` is 4 because 1 is an `int`.  However, if a number does not fit to an
`int`, a higher type will be used.  For example, 4294967296 (2^32) will be stored
in 8 bytes, and `sizeof (4294967296)` is 8.

Does it sound confusing?  Do not worry, we will give you specific rules later.

:wrench: verify that numbers that do not fit in an `int` will have a size of 8
bytes.

## Examples

Aassuming `char c;` declaration:
- `sizeof (999)` is 4 as "999" is an integer by definition.
- `sizeof (c)` is 1
- `sizeof (c + c)` is 4 as `+` is a binary operator and the integer promotion
  kicks in
- `sizeof (++c)` is still 1 as `++` is an unary operator for which the integer
  promotion rules do not apply.
- `sizeof (+c)` is 4 as for unary `+` and `-`, the integer promotion is applied.
  - You just need to know or check the spec if you do not remember.  Most
    of the time it does not matter but do not fool yourself, if you do not
    know details like that in C, it will bite you sooner or later.
  - remember [A Case Study of Toyota Unintended Acceleration and Software
    Safety](https://users.ece.cmu.edu/~koopman/pubs/koopman14_toyota_ua_slides.pdf)
    from the [first class](/modules/intro.md)
- `sizeof (1LL)` will usually be 8 as `long long` is usually 8 bytes.

It gets more interesting if unsigned and signed numbers are involved.  Eg. a
`signed int` is promoted to an `unsigned int` if one of the operands is
unsigned.

The above is called *implicit type conversion*.  There is also *explicit type
conversion* (called *casting*) which we will deal with later.

I suggest you try these out with `printf("%zu", ...)`.  `%zu` (see "man 3
printf") matches the return type of the `sizeof` operand.  The exact unsigned
numeric type of what `sizeof` returns may differ in different implementations so
`%zu` will work anywhere.
