# Arithmetic type conversions

In (very) general, if *binary* operators have operands of different types, the
"lower" is promoted to "upper".  E.g. if one operand is a `long` and the other
is an `int`, the other operand is promoted to a `long`.  An unsigned type is
always higher to its corresponding signed type.  That is, if summing up a
`signed int` with an `unsigned int`, the signed one will be converted to an
unsigned first.

To give you a glimpse into what this means:

```C
int
main(void)
{
	/* Also try with '-10 + 1U + 10U' */
	printf("%ld\n", -10 + 1U + 10L);
}
```

You would expect the result to be `1`, right?

```
$ cc main.c
$ ./a.out
4294967297
```

However, `-10 + 11U + 10L` would result in `11`, and `-1 + 2U` would result in
`1`.

What is more, in most operations (for every operator, the spec says what is
done in this respect), `char` and `short` integer operands are *promoted* to
an `int`, or to an `unsigned int` if they do not fit in an `int`.  That
conversion is called *integer promotion*.  This is done to make the language
runtime fast (on x86 32-bit arithmetics can be much faster than when using
16-bit operands).

  - note that the only way an `unsigned short` would not fit a (signed) `int`
    but fit an `unsigned int` is if both types had the same size (e.g. 4 bytes).
    You will probably not use such a compiler/platform combination, ever.

*Most operations* means all binary operators.  A ternary operator as well.  And
even some unary operators.

`sizeof (1)` is 4 because 1 is an `int`.  However, if a number does not fit to
an `int`, a higher type will be used.  For example, `4294967296` (2^32 =
`UINT_MAX + 1`) will be stored in 8 bytes, so `sizeof (4294967296)` is 8.

Does it sound confusing?  Do not worry, we will give you specific rules later.

:wrench: verify that numbers that do not fit in an `int` will have a size of 8
bytes.

## Examples

Assuming `char c;` declaration, then:

- `sizeof (999)` is 4 as `999` is an `int` by definition.
- `sizeof (c)` is 1, always
- `sizeof (c + c)` is 4 as `+` is a binary operator and the integer promotion
  kicks in, as mentioned above
- `sizeof (++c)` is still 1 as `++` is an unary operator for which the integer
  promotion rules do not apply.
- `sizeof (+c)` is 4 as for unary `+` and `-`, the integer promotion is applied.
  - You just need to know or check the spec if you do not remember.  Most
    of the time it does not matter but do not fool yourself, if you do not
    know details like that in C, it will bite you sooner or later.
  - remember [A Case Study of Toyota Unintended Acceleration and Software Safety](https://users.ece.cmu.edu/~koopman/pubs/koopman14_toyota_ua_slides.pdf)
    from the [first class](/modules/intro.md)
- `sizeof (1LL)` will usually be 8 as `long long` is usually 8 bytes.

It gets more interesting if unsigned and signed numbers are involved.  E.g. a
`signed int` is promoted to an `unsigned int` if one of the `int` operand is
unsigned.

The above is called *implicit type conversion*.  There is also *explicit type
conversion* (called *casting*) which we will deal with later.

I suggest you try these out with `printf("%zu", ...)`. The `%zu` format string
(see the `printf` manual page in section 3 on Unix systems) matches the return
type of the `sizeof` operand.  The exact unsigned numeric type of what `sizeof`
returns may differ in different implementations so `%zu` will work anywhere.

## :wrench: Quiz 1

- what is the result if `0xff` `signed char` and `0xff` `unsigned char` are
  compared using the `==` operator ?
  - write down the hexadecimal representation of the integers corresponding to
    the 2 chars with `printf()`

#solution int-promotion.c

- note that if the `b` character was defined as `char b` the result might be 1
  because it is up to the compiler to choose whether `char` is signed or
  unsigned.  Usually it is signed though. There are compiler options to specify
  this, e.g. GCC has `-funsigned-char` and `-fsigned-char`

## :wrench: Quiz 2

Will the program print the whole array ?
  - try to come up with reason of the expected behavior before running the
    program.

#source whole-array.c
