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

#source not-one.c

What is more, in most operations (for every operator, the spec says what is
done in this respect), `char` and `short` integer operands are *promoted* to
an `int`, or to an `unsigned int` if they do not fit in an `int`.  That
conversion is called *integer promotion*.  This is done to make the language
runtime fast (on x86 32-bit arithmetics can be much faster than when using
16-bit operands).

  - Note that the only way an `unsigned short` would not fit a (signed) `int`
    but fit an `unsigned int` is if both types had the same size (e.g. 4 bytes).
    You will probably not use such a compiler/platform combination, ever.

The **most operations** from the above sentence means all binary operators.  A
ternary operator as well.  And even some unary operators.

`sizeof (1)` is 4 because 1 is an `int`.  However, if a number does not fit to
an `int`, a higher type will be used.  For example, `4294967296` (2^32 =
`UINT_MAX + 1`) will be stored in 8 bytes, so `sizeof (4294967296)` is 8.

Does it sound confusing?  Do not worry, we will give you specific rules later in
#module arithmetic-promotion-and-conversions.md *Arithmetic/integer promotion and conversion* section.

:wrench: Verify that numbers that do not fit in an `int` will have a size of 8
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
	- remember [A Case Study of Toyota Unintended Acceleration and Software
	  Safety](https://users.ece.cmu.edu/~koopman/pubs/koopman14_toyota_ua_slides.pdf)
	  from the [first class](/modules/intro.md)
- `sizeof (1LL)` will usually be 8 as `long long` is usually 8 bytes.

It gets more interesting if unsigned and signed numbers are involved.  E.g. a
`signed int` is promoted to an `unsigned int` if one of the `int` operand is
unsigned.  This is called an *implicit type conversion*.  There is also
*explicit type conversion* (called *casting*) which we will deal with later in
#module arithmetic-promotion-and-conversions.md *Arithmetic/integer promotion and conversion* section.

I suggest you try these out with `printf("%zu", ...)`. The `%zu` format string
(see the `printf` manual page in section 3 on Unix systems) matches the return
type of the `sizeof` operand.  The exact unsigned numeric type of what `sizeof`
returns may differ in different implementations so `%zu` will work anywhere.

## Example 2

If `long` is 8 bytes, and `int` 4 bytes, then `-1L < 1U` is true as you might
expect because `1U` is converted to a `long` because a `long` can represent all
values an `unsigned int`.

However, if both types are 4 bytes, the relational expression is false!  The
reason is that in this case, as both types has the same *integer conversion
rank* (C99 6.3.1.1), the signed is converted to unsigned.  See *6.3.1.8 Usual
arithmetic conversions*, paragraph *1*, for the details.

Two's complement representation of -1 in 4 bytes is:

```
(1) take absolute value of 1	00000000.00000000.00000000.00000001
(2) one's complement		11111111.11111111.11111111.11111110
(3) add 1 to get 2's complement	11111111.11111111.11111111.11111111
```

which is `2^32 - 1` when interpreted as unsigned quantity.

Just `printf("%u\n", -1)` to see it will print `4294967295` (use the Unix/Linux
`bc` command and type `2^32-1` to verify).

#source signed-plus-unsigned.c
#source signed-to-unsigned.c

## Example 3

The assymetry of the negative/positive interval can lead to the program crashing
on architectures that detect it. This is consequence of hardware handling rather
than the language.

#source crashme.c

- run with `-INT_MIN` (see `limits.h`) and `-1`.  `INT_MIN` is usually
  `-2147483648`. The program would normally yield `2147483648` (positive number)
  however that would be `INT_MAX + 1`.
- works in 64-bit mode as well due to int being passed in 32-bit registers

```
$ cc -m64 crashme.c
$ ./a.out 2147483648 -1
-2147483648 -1
Floating point exception: 8
$ echo $?
136
$ kill -l 136
FPE

$ cc -m32 crashme.c
$ ./a.out 2147483648 -1
2147483647 -1
$
```

## :wrench: Quiz 1

- what is the result if `0xff` `signed char` and `0xff` `unsigned char` are
  compared using the `==` operator ?
	- write down the hexadecimal representation of the integers
	  corresponding to the 2 chars with `printf()`

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
