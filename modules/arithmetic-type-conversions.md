# Arithmetic type conversions

In (very) general, if *binary* operators have operands of different types, the
"lower" is promoted to "upper".  Eg. if one operand is a long double, the other
operand is promoted to a long double.

What is more, char and short int operands are converted to ints, and to unsigned
ints if they do not fit in an int.  That conversion is called *integer
promotion*.  This is done to make the runtime fast (on x86 32-bit arithmetics
can be much faster than when using 16-bit operands).

sizeof (1) is 4 because 1 is an int.  However, if a number does not fit to an
int, a higher type will be used.  For example, 4294967296 (2^32) will be stored
in 8 bytes, and "sizeof (4294967296)" is 8.

Examples (assuming `char c;` declaration);
- sizeof (999) is 4 as "999" is an integer by definition.
- sizeof (c) is 1
- sizeof (c + c) is 4 as "+" is a binary operator and the integer promotion
  kicks in
- sizeof (++c) is still 1 as `++` is an unary operator for which the integer
  promotion rules do not apply.  However, they do apply for unary `+` and `-`.
- sizeof (1LL) will usually be 8 as "long long" is usually 8 bytes.

It gets more interesting if unsigned and signed are involved.  Eg. a signed int
is promoted to an unsigned int if one of the operands is unsigned.

The above is called "implicit type conversion". There is also "explicit type
conversion" (called "casting") which we will deal with later.

I suggest you try these out with `printf("%zu", ...)`.  `%zu` (see "man 3
printf") matches the return type of the `sizeof` operand.  The exact unsigned
numeric type of what `sizeof` returns may differ in different implementations so
`%zu` will work anywhere.


