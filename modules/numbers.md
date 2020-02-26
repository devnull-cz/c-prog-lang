# numbers and types

- 1, 7, 20000 are always integers of type `int` if they fit (the range is
  [-2^31, 2^31 - 1] on 32/64 bit CPUs)
- hexadecimal numbers start with `0x` or `0X`.  Eg. `0xFF`, `0Xaa`, `0x13f`, etc.
  octal numbers start with `0`.  Eg. `010` is 8 in decimal.  Also remember the
  Unix file mask (umask), eg. `0644`.

- `'A'` is `int`.  See `man ascii`.  The ASCII standard defines characters with
  values 0-127.

- `float`, `double`
  - `man 3 printf`, see `%f` is of type `double`.  You can use:

```C
	  printf("%f\n", float)
```

- floats are automatically converted to doubles if used as arguments in
  functions with variable number of arguments (known as a "variadic function"),
  i.e. like printf()

- `char` (1 byte), `short` (usually 2 bytes), `long` (4 or 8 bytes), `long long`
  (usually 8 bytes).  It also depends on whether your binary is compiled in 32
  or 64 bits.

- as `'X'` is `int` but within 0-127, it's OK to do the following as it will fit
  even if `char` is signed:
```C
	char c = 'A';
```

## signedness

- each integer type has a `signed` and `unsigned` variant.  By default, the
  numeric types are signed aside from char which depends on the implementation.
  If you need an unsigned type, use `unsigned` reserved word.
```C
  signed int;
  unsigned int;
  unsigned long;
  unsigned long long;
  ...
```
- for ints, you do not need to use the `int` keyword, ie. `signed i`,
  `unsigned u` are valid but it is recommended to use `signed int i` and
  `unsigned int u` anyway.

- You can use `long int` and `long long int` or just `long` and `long long`,
  respectively.  The latter is mostly used in C.

- `char` and `short int` is converted to `int` in variadic functions (we will
  talk more about integer conversions later in semester).  Eg.  the following is
  OK as the compiler will first convert variable `c` to `int` type, then put it
  on the stack (Intel x32 passing argument convention) or in a register
  (Intel x64 convention).
```C
	/* OK */
	char c;
	printf("%d\n", c);

	/* OK */
	short sh;
	printf("%d\n", sh);
```
## modifiers for printf

- `l` for long, eg. `long l; printf("%ld\n", l);`
- `ll` for long long, eg. `long long ll; printf("%lld\n", ll);`

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
- the following is a problem though if compiled in 32 bits as you put 4 bytes on
  the stack but printf will take 8 bytes.  Older compilers may not warn you at
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
 - when compiled in 64 bits, it is still as wrong as before but it will work
   anyway as 13 is assigned to a 64 bit register (because of x64 ABI).
```
	$ cc -m64 wrong-modifier.c
	wrong-modifier.c:6:19: warning: format specifies type 'long
	long' but the argument has type 'int' [-Wformat]
		printf("%lld\n", 13);
			~~~~     ^~
			%d
	1 warning generated.
```

## suffixes

- you can explicitly specify larger integers with suffices

	- `13L` and `13l` is long
	- `13LL` and `13ll` is long long (`Ll` and `lL` is illegal)
	- `13u` and `13U` is unsigned int
	- `13lu` and `13LU` is unsigned long
	- `13llu` and `13LLU` is unsigned long long

- so, `0xFULL` and `0XFULL` is unsigned long long 15 :-)
```C
	printf("%llu\n", 0xFULL);
	// --> 15
	printf("%lld", 13LL);	/* OK */
	/* in general NOT OK as long may be 4 bytes while long long 8 bytes */
	printf("%ld", 13LL);
```

- `\ooo` and `\xhh` are character sized bit patterns, either specified
  as octal or hexadecimal numbers.
