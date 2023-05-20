# Bitwise operations

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

When shifting to the right, it depends on the signedness of the number.
For unsigned values the upper bits are filled with zeroes.
If the number is signed and negative (i.e. starts with bit 1 in two's complement
representation), the behavior is implementation dependent.
Usually the value it is _sign-extended_, i.e. filled with 1's.

#source left-right-shift.c

## Common uses of bitwise operators:

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

Another common case is to use an integer type to store multiple kinds of
information, with mask to extract the parts. Here, a `ungisned short` type
stores the byte value and associated flags:

```C
#define	VALUE_MASK	0xff
#define	FLAG_MASK	0xff00

#define	ONE		0x0100
#define	TWO		0x0200

unsigned short n = 16 | ONE | TWO;

if ((n & FLAG_MASK) & ONE)
	printf("ONE\n");

printf("%hhu\n", n & VALUE_MASK);
```

## Binary operators and integer promotion

When working with bitwise operators, operands are promoted the same way
as we learned in
#module arithmetic-promotion-and-conversions.md Conversions and promotions

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
