# Bitwise operations

:wrench: Task

Print `argv[1]` in binary (assume it is a correct decimal number).  Note that
`printf`(3) does not have a conversion specifier for it (unlike 'x' for hexa and
'o' for octal).  Limit the input to positive `int`s.  Do not use bit operators
even if you know how to (ie. do NOT use `>>` etc.)

To verify, use bc(1) with `obase=2`.  E.g.:

```
$ bc
obase=2
10
1010
255
11111111
2^31-1
1111111111111111111111111111111

$ ./a.out 2147483647
1111111111111111111111111111111
$ ./a.out 255
11111111
$ ./a.out 348508345
10100110001011101000010111001
```

You can also use `obase=8`, `obase=16`, etc.  Note that bc(1) takes only capital
letters as digits, ie. use "E4" for 0xe4, not "e4".  "e4" is treated as a
variable:

```
$ bc
ibase=16
obase=2
e4
0
E4
11100100
```

#source print-in-binary.c

Bitwise operators are as follows:

Operator | Meaning
--- | ---
`&`	| bitwise AND
`\|`	| bitwise OR
`^`	| bitwise XOR
`<<`	| left shift
`>>`	| right shift
`~`	| one's complement (unary)

Note, individual bits are being processed.  I.e.:

```
316 & 978			-> convert to binary to see it
100111100 & 1111010010		-> do logical AND bit by bit now

0100111100
1111010010
----------
0100010000	== 272 (use ibase=2 with bc(1) to verify)
```

So,

```
((338 & 978) == 272).	// == is of higher prority than &
```

Common uses of bitwise operators:

```C
n = n & 01777;			// zero out some highest bits

/*
 * Setting individual flags.  Note that each of the flags has
 * just one bit set.
 */
#define	LIGHT_OFF	0x0000
#define	LIGHT_GREEN	0x0001
#define	LIGHT_RED	0x0002
#define	LIGHT_BLUE	0x0004
#define	LIGHT_YELLOW	0x0008
#define	LIGHT_VIOLET	0x0010
#define	LIGHT_WHITE	0x0020
// ...

lights = lights | LIGHT_YELLOW;	// turn on yellow light
lights = lights & ~LIGHT_RED;	// turn off red light
```

## Binary operators and integer promotion

When working with bitwise operators, operands are promoted the same way
as we learned in lecture 05 (see "Various conversions and promotions").
That means:

```
13U & -1				-> promote int (-1) to unsigned,
					   i.e.  promote -1 to unsigned.
					   You get:

13 & 4294967295				-> now convert to binary
1101 & 11111111111111111111111111111111	-> the result clearly is 1101
```

#source conv-and-prom-with-bitwise-ops.c

:wrench: Task: rewrite `print-in-binary.c` using bitwise operators

:wrench: Task: count 1 bits in a number (`argv[1]`).

```
$ ./a.out 337
4
$ ./a.out 13375
9
```
