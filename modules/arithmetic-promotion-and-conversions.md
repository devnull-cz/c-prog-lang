# Arithmetic/integer promotion and conversion

NOTE: the following is a simplified version of what is in the standard.  You
need to consult the specification if unsure.  See
#module c99-standard.md the standard
for the PDF link.

We already mentioned some of this in an
#module arithmetic-type-conversions.md Arithmetic type conversions
section but now we will be more specific.

## Integer promotion vs integer conversion vs arithmetic conversions

First, let's define three different actions, then we will go through those one
by one.

*Integer promotion*: `char` -> `int`; `short` -> `int`; or both to `unsigned
int` if the value does not fit a `signed int` (may happen if a `short int` is of
the same size as an `int`, and `unsigned short` is used).

*Integer conversion*: converting integers (e.g. assigning a `signed long` to an
`unsigned char`, or assigning an `unsigned int` to a `signed char`)

*Arithmetic conversion*: many operators cause conversions.  The effect is to
bring the operands into a common type **before** the operator is applied.  For
example:

```C
int i;
unsigned long long ull;

i + ull;	// type of the result is unsigned long long and 'i'
		// is converted to unsigned long long BEFORE '+' is
		// applied.  See below what happens if 'i' contains a
		// negative number.
```
## Integer Promotion

Integer promotion (we promote `char`s and `short`s **only** here) usually
happens with binary and ternary operators before arithmetic conversion happens.
It sometimes happens with unary operators as well.  You need to consult the
specification.  For example:

```
++ and --	*NO* integer promotion
! (negation)	*NO* integer promotion
+ and -		integer promotion happens for both unary and binary operations
```

That means for `char c`:

```C
sizeof (c)	// is	1
sizeof (++c)	// is	1
sizeof (--c)	// is	1
sizeof (!c)	// is	1
sizeof (+c)	// is	4
sizeof (-c)	// is	4
sizeof (c + 1)	// is	4
// ...
```

Note that we already know that `c` is **never** modified as the expression in
`sizeof` is never evaluated.  See the
#module sizeof.md sizeof module
for to review the knowledge.

### Printing `sizeof` value

Remember, to `printf` a value of `sizeof`, use it like the following (the
`sizeof` result is always unsigned, and the `z` modifier makes sure its size
(usually 4 or 8 bytes) matches the implementation, ie. whatever `size_t` is):

```C
printf("%zu\n", sizeof (c));
```

Consult the `printf` man page if unsure about printf conversions and modifiers.

*Integer promotion also happens in arguments of variadic functions* (eg.
`printf`).  That is why the following works as expected:

```C
char c = 'A';
printf("%c", c);
```

printf(3) man page says:

```
c	The int argument is converted to an unsigned char, and the
	resulting character is written.
```

So it means that `%c` expects an `int` but we put a `char` there.  However,
since an integer promotion is applied on non-fixed arguments of
#module variable-argument-functions.md variadic functions,
`c` is converted to an `int` **before** it is used as an argument to `printf`.
Note that on a 64-bit x86 platform, this conversion means no extra code as the
argument (= `char`) is just put to a 32-bit register.

## Integer conversion

This is about **converting integers only**.

There are three parts when converting integers:

1. Assigning an integer to another integer while the source value fits into
the target -> the result is specified by
#module c99-standard.md the standard.
The result is the same value.

2. Assigning any integer to an **unsigned** integer -> result specified by the
standard, see below.

3. Assigning an integer to a **signed** integer and the value does **not** fit.
The standard says the result is *implementation-defined*.  It means the
implementation (i.e. the compiler) must choose how to behave in such a situation
and **must** document it.  See [the standard](/modules/c99-standard.md), section
3.4.1, for the precise definition.  See also
#module types-of-behavior.md types of behavior.

### Rule 1: Assigning number fits the integer object

The first rule is simple and needs not much discussion.

```C
long long int li = 13;
/* Is it guaranteed the one byte 'c' will be 13 even that sizeof(li) is 8. */
signed char c = li;
```

Note that the case already showed above, `char c = 'A';`, also fits this rule.
`'A'` is a character constant from ASCII, so its type is an `int`, and its value
fits a `char` no matter whether the `char` type is signed or unsigned.  ASCII by
its specification only uses values 0-127 and even `signed char` is required to
accommodate that range.  So, as `'A'` fits the `c` object, this situation is
covered by the first rule.

### Rule 2: Integer to an unsigned integer

> 6.3.1.3 Signed and unsigned integers
...
...if the new type is unsigned, the value is converted by repeatedly
adding or subtracting one more than the maximum value that can be represented in
the new type until the value is in the range of the new type.

Use bc(1) to work with big numbers:

```
$ bc
2^32
4294967296
(2^32 + 17) % 2^16
17
...
...
```

So, the following happens when assigning the numbers below to an `unsigned
char`:

```C
unsigned char c = 257;		// -> 1 (257 - 256)
unsigned char c = 258;		// -> 2 (258 - 256)
unsigned char c = 1000;		// -> 232 (1000 - 3*256)

/* -> 239 (4294967279 - 2^32 + 256), and it's the same as 4294967279 % 256 */
unsigned char c = 4294967279;
```

Examples in C:

```C
/* 'c' will be 24 */
unsigned char c;
c = -1000;		// -1000 + 4 * 256

/* 'i' will be 4294967286 */
unsigned int i;
i = -10;		// -10 + 2^32
```

### Rule 3: Assign to a signed type when the value does not fit

When any integer is converted to a signed type, the value is unchanged if it can
be represented in the new type (that is rule 1 above) and **is
implementation-defined otherwise.**

For gcc, that *implementation-defined* behavior is documented in
[Integers
implementation](https://gcc.gnu.org/onlinedocs/gcc/Integers-implementation.html)

```
  The result of, or the signal raised by, converting an
  integer to a signed integer type when the value cannot be
  represented in an object of that type (C99 6.3.1.3):

	For conversion to a type of width N, the value is
	reduced modulo 2^N to be within range of the type; no
	signal is raised.
```

So, with `gcc` (and probably any other compilers you might meet today), this
means the wrap-around rule is applied for signed integers as well.  However, let
us repeat that the following is an example of implementation-defined behavior
tied to the gcc compiler.  Note that by default, gcc has `char` signed.

```C
char c = 128;	// 128 - 256, ie. -128 will be in 'c'.  Might surprise
		// one, right?
```

And this may be equally confusing until one understands how it works:

```C
char c = 128;

printf("%x\n", c);
```

Compile and run.  As `printf` is a variadic function, *integer promotion* is
performed on its integer arguments.  So, as `c` is actually -128, converted to
a 4 byte `signed int` yields `11111111111111111111111110000000` as its binary
representation, using the two's complement.  And as the `%x` modifier prints an
**unsigned** `int` as hexa, *Rule 2* is applied to convert it to an `unsigned
int`, and that results in a much larger number printed:

```
$ ./a.out
ffffff80
```

`printf`'s `hh` modifier is for printing either a signed or unsigned `char` (as
a number, do not confuse it with the `c` modifier which prints a character), `h`
for an unsigned or signed `short`.  Note that `i` below is first converted to an
`int` if it is not already, as arguments of variadic functions goes through
*integer promotion*, as we already know.  Then, it is converted to a `char`
**inside** `printf`.

```C
/* This will print 1 if compiled with gcc. */
int i = 257;
/*
 * As 'd' is signed, this is for a signed char.  'hhu' would be for an unsigned
 * char.
 */
printf("%hhd\n", i);
```

The compiler will probably warn you to let you know that your `int` might be
truncated.

```
xxx.c:10:19: warning: format specifies type 'char' but the argument has
	     type 'int' [-Wformat]
printf("%hhd\n", i);
	~~~~     ^
	%d
```

### Generic integer conversion algorithm

BTW, when mentioning above those three parts when converting integers, it does
not hurt to cite the
#module c99-standard.md C99 standard
in full on this.
The following section covers all the integer conversions we went through above.
The below mentioned *implementation-defined signal* might be to print an error
and exit, for example.

```
6.3.1.3 Signed and unsigned integers

1 When a value with integer type is converted to another integer type other than
 _Bool, if the value can be represented by the new type, it is unchanged.

2 Otherwise, if the new type is unsigned, the value is converted by repeatedly
  adding or subtracting one more than the maximum value that can be represented
  in the new type until the value is in the range of the new type.

3 Otherwise, the new type is signed and the value cannot be represented in it;
  either the result is implementation-defined or an implementation-defined
  signal is raised.
```

Example: #source integer-conversion.c

## Arithmetic conversion

Simply put, arithmetic conversion is about converting all arguments of an
operator to the smallest common type **before** the operator is applied.  That
includes arithmetic operators as well as logical operators (>, <, <=, ==, >=)

The details are in *6.3.1.8 Usual arithmetic conversions*, paragraph *1*.

Example:

```C
char c;
signed int i;
unsigned int u;
long long ll;

c + i + u + ll;
```

We will learn about associativity later, but let's accept that the compiler
actually assumes the following:

```C
((c + i) + u) + ll)
```

What happens:

1. `c` is converted to an `int` based on Integer Promotion with a binary `+`
operator
2. the result type of `(c + i)` is an `int` as both operands are `int`s
3. that result is converted to an `unsigned int` (= type of `u` which is
"bigger" than `int`) using the Integer Conversion we just introduced above.
4. the result type of `(c + i + u)` is then an `unsigned int`
5. the result from 4) is then converted to a `long long` because of the "bigger"
type of `ll`
6. the `long long` is the result type of the whole expression

Note that at every step, Integer Conversion rules were applied.  Also, an
unsigned integer type is "bigger" than the corresponding signed type, see
#module rank.md on the *integer conversion rank*.

```C
int i;
unsigned int u;

i + u;		// 'i' is first converted to unsigned int
```

That is why `-1 > 1U` is **TRUE** since `-1` is first converted to an `unsigned
int`, ie.  `-1` is converted into `-1 + 2^32`, i.e. `4294967295`, and the
expression is then evaluated as:

```C
(4294967295U > 1U)
```

The arguments of ternary operator are also first converted to a common type no
matter which branch will be returned.  For example:

```C
unsigned int i = 0 ? 1U : -1;
printf("%u\n", i);		// will print 2^32-1 (ie. 4294967295)
```

However, if you do this:

```C
int i = 0 ? 1U : -1;
```

Then the result of the ternary expression is `4294967295` but then it is
converted to a `signed int`.  And `4294967295` does not fit an `int` whose range
in two's complement (gcc) is [-2^31, 2^31-1].  So, if we rely on gcc
implementation-defined behavior, there is a modulo operation to the rescue and
we get `-1`:

```
// (-1 + 4294967295) == 2^32
int
main(void)
{
	int i = 0 ? 1U : -1;
	printf("%d\n", i);
}
```

The compiler **may** (or may not!) warn you as you are triggering something that
is implementation-defined:

```
$ cc main.c
"main.c", line 6: warning: initializer does not fit or is out of
range: 0xffffffff
$ ./a.out
-1
```

## Signed numbers

The C99 spec does **not** say how signed numbers are internally stored.  That is
just an implementation detail for it.  There are other ways to do it than via
the two's complement.  See [Signed number
representations](https://en.wikipedia.org/wiki/Signed_number_representations).

However, gcc, clang, and all other compilers you probably ever meet use two's
complement, as documented on [Integers
implementation](https://gcc.gnu.org/onlinedocs/gcc/Integers-implementation.html)

```
-  Whether signed integer types are represented using sign and
   magnitude, two's complement, or one's complement, and
   whether the extraordinary value is a trap representation or
   an ordinary value (C99 and C11 6.2.6.2).

	GCC supports only two's complement integer types, and
	all bit patterns are ordinary values.
```

Note that in contrast to the previous C standards, the C23 specification
requires two's complement to represent negative integers.

# :wrench: Assignment to practice your knowledge

Try to figure out using bc(1) and what you have just learned what will be in the
variables:

```C
/*
 * Let's assume that:
 *
 *      short int is 2 bytes
 *      int is 4 bytes
 *      long is 8 bytes
 *      long long is 8 bytes
 *
 * Compile with "gcc -m64" to match the above.
 *
 * Let's assume that we use gcc that uses modulo to fit when assigning to a
 * signed integer.
 *
 * Include <limits.h> for INT_MIN (-2^31) and INT_MAX (2^31 - 1).
 */

/*
 * Use bc(1) to manually compute the values of the left sides.  When done,
 * incorporate into the C code, compile, and verify you got it right.
 */

unsigned long long ull = -13;            // Use %llu in printf() to verify.
signed char sc = 999;                    // %d
short int si = -1;                       // %hd
unsigned int ui = -1;                    // %u
unsigned short int usi = 999999;         // %hu
signed char sc = 0 ? -10 : 0U;           // %d
signed char sc = -1 ? -10 : 0U;          // %d
long long ll = 1U + -10;                 // %lld
unsigned long long ull = 1U + -10;       // %llu
unsigned short int usi = INT_MIN + 13LU; // %hu
unsigned short int usi = -INT_MAX + 13U; // %hu
signed char sc = 129;                    // %d

/* What is printed? */
printf("%hhu\n", -3);
printf("0x%hhx\n", -3);
printf("%c\n", 321);
printf("%c\n", -191);
```

The code is in here to verify:
#source integer-conversion-assignment.c

Also check the following code and try to figure out what is going to be printed:

#source int-promotion.c

Now you also know everything you need to know to figure out what happens in the
following code.  Hint, not all elements are printed as it seems from the first
look.  Another hint -- `sizeof`'s type is unsigned, and the logical operator
triggers the Arithmetic Conversion, see above.

#source whole-array.c
