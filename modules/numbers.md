# Numbers and types

- For example, the `1`, `7`, and `20000` integer literals are always integers of
  type `int` **if they fit** in.
  - The range of an `int` is [-2^31, 2^31 - 1] on 32/64 bit CPUs, that means 4
    bytes of storage.  However, an `int` may be stored in only two bytes as
    well.  The range would be [-2^15, 2^15 - 1] then.  You will likely never
    encounter such old platforms unless you look for them.
  - A larger number will automatically become a `long int`, then a `long long
    int` if the number literal does not fit a (signed) `long`.  That means if
    an `unsigned long long` type is stored in 8 bytes, one cannot use a decimal
    constant of `2^64` in the code and expect it to hold such a value:

```
$ cat main.c
int
main(void)
{
	unsigned long long ull = 18446744073709551616;
}

$ gcc -Wall -Wextra -Wno-unused main.c
main.c: In function ‘main’:
main.c:4:34: warning: integer constant is too large for its type
    4 |         unsigned long long ull = 18446744073709551616;
      |                                  ^~~~~~~~~~~~~~~~~~~~
```

  - If you printed `ull` (using `%llu` as for `unsigned long long int`), you
    would probably get `0`.  More on that later.

- Hexadecimal numbers start with `0x` or `0X`.  Eg. `0xFF`, `0Xaa`, `0x13f`,
  etc.  In contrast to decimal constants, one can use a hexa constant for
  `2^64`, which is `0xFFFFFFFFFFFFFFFF`, even if `unsigned long long` is stored
  in 8 bytes.  More on that later.
- Octal numbers start with `0`.  Eg. `010` is 8 in decimal.  Also remember the
  Unix file mask (umask), eg. `0644`.

- `'A'` is called *a character constant* and is always of type `int`.  See `man
  ascii` for their numeric values.  The ASCII standard defines characters with
  values 0-127.

- Note when we say a *character*, we mean a value that represents a character
  from the ASCII table.  A character is not the same thing as `char`.

- Types `float`, `double`
	- If you `man 3 printf`, you can see that `%f` is of type `double`.  You
	  can use:

```C
float pi = 3.14
printf("%f\n", pi);
```

	- `float`s are automatically converted to `double`s if used as arguments
	  in functions with variable number of arguments (known as *variadic
	  function*), i.e. like printf()

- `char` (1 byte), `short` (usually 2 bytes), `long` (4 or 8 bytes), `long long`
  (usually 8 bytes, and can not be less).  It also depends on whether your
  binary is compiled in 32 or 64 bits.
	- :wrench: See what code your compiler emits by default (i.e. without
	  using either `-m32` or `-m64` options)
		- Use the `file` command to display the information about the
		  binary.

- See also *5.2.4.2 Numerical limits*
#module c99-standard.md in the C spec.
  For example, an `int` must be at least 2 bytes but the C spec does not prevent
  it from being 8 bytes in the future.

- `char`s and `short`s are automatically converted to `int` if used as arguments
  in variadic functions, and also if used as operands in many operators.  More
  on that later.

- As `'X'` is an `int` but within 0-127 (see above on the ASCII standard), it is
  OK to do the following as it is guaranteed to fit even when the `char` type is
  signed:

```C
char c = 'A';
```

- In `printf`, you need to use the same type of an argument as is expected by
  the conversion specified.  Note that e.g. integers and floating point numbers
  have different representation, and printing an integer as a double (and vice
  versa) will lead to unexpected consequences.  More on that later.

```
printf("%f\n", 1);

$ ./a.out
0.000000
```

#source print-int-as-double.c

## Signedness

- Each integer type has a `signed` and `unsigned` variant.  By default, the
  numeric types are signed aside from `char` which depends on the implementation
  (of the C compiler).  If you need an unsigned type, use `unsigned` reserved
  word.

```C
signed int si;	// not used though, just use 'int si'
unsigned int ui;
unsigned long ul;
unsigned long long ull;
...
```

- For `int`s, you do not even need to use the `int` keyword, ie. `signed i`,
  `unsigned u` are valid but it is recommended to use `int i` and `unsigned int
  u` anyway.

- You can use `long int` and `long long int` or just `long` and `long long`,
  respectively.  The latter is mostly used in C.

- `char` and `short int` are converted to `int` in variadic functions (we will
  talk more about integer conversions later in semester).  That is why the
  following is correct as the compiler will first convert variable `c` to `int`
  type, then put it on the stack (common argument passing convention on
  [IA-32](https://en.wikipedia.org/wiki/IA-32))
  or in a register up to certain number of arguments (common x86-64
  [calling convention](https://en.wikipedia.org/wiki/X86_calling_conventions)).

```C
/* OK */
char c = 127;
printf("%d\n", c);

/* OK */
short sh = 32768;
printf("%d\n", sh);
```

## Modifiers for printf()

- `l` for `long`, eg. `long l; printf("%ld\n", l);`
- `ll` for `long long`, eg. `long long ll; printf("%lld\n", ll);`

- `u` is unsigned, `x` is unsigned hexa, `X` is unsigned HEXA

```C
unsigned int u = 13;
printf("%u\n", u);

unsigned long long llu = 13;
printf("%llu\n", llu);

unsigned int u = 13;
printf("%x\n", u);
// --> d
printf("%X\n", u);
// --> D
```

- The following is a problem though if compiled in 32 bits as you put 4 bytes on
  the stack but `printf` will take 8 bytes.  Older compilers may not warn you at
  all!

```
/* DEFINITELY NOT OK.  Remember, 13 is of the "int" type. */
printf("%lld\n", 13);

$ cc -m32 wrong-modifier.c
wrong-modifier.c:6:19: warning: format specifies type 'long
long' but the argument has type 'int' [-Wformat]
	printf("%lld\n", 13);
		~~~~     ^~
		%d
1 warning generated.
$ ./a.out
2026120757116941
```

 - When compiled in 64 bits, it is still as incorrect as before but it will
   probably print `13` anyway as `13` is assigned to a 64 bit register (because
   of commonly used calling convention on [x86-64](https://en.wikipedia.org/wiki/X86-64)).
   So, if you use that code successfully in 64 bits you might be
   surprised if the code is then compiled in 32 bits and "suddenly gets broken".
   It was broken from the very beginning.

```
$ cc -m64 wrong-modifier.c
wrong-modifier.c:6:19: warning: format specifies type 'long
long' but the argument has type 'int' [-Wformat]
	printf("%lld\n", 13);
		~~~~     ^~
		%d
1 warning generated.
$ ./a.out
13
```

#source wrong-modifier.c

## Suffixes

- You can explicitly specify integer constants with different integer types
  using suffices:

	- `13L` and `13l` is a `long`
	- `13LL` and `13ll` is a `long long` (`Ll` and `lL` is illegal)
	- `13u` and `13U` is an `unsigned int`
	- `13lu` and `13LU` is an `unsigned long`
	- `13llu` and `13LLU` is an `unsigned long long`

- So, `0xFULL` and `0XFULL` is an `unsigned long long` 15 :-)

```C
printf("%llu\n", 0xFULL);
// --> 15
printf("%lld", 13LL);	/* OK */
// --> 13
/* NOT OK as long may be 4 bytes while long long is 8+ bytes */
printf("%ld", 13LL);
// --> ??
```

- Escape sequences `\ooo` and `\xhh` (not `\Xhh`) are character sized bit
  patterns, either specified as octal or hexadecimal numbers, and representing a
  single character.  They can be used both in string and character constants
  constants.

```C
printf("\110\x6F\154\x61");	// Used in a string literal.
printf("%c\n", '\x21');		// Used in a character constant.
// -> Hola!
```
