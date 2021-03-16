# Integer Literals

- An *integer literal* can be a decimal, octal, or hexadecimal constant. 

- so, all of these are equal:
```C
	printf("%c\n", 'A'); // will print an integer as a character
	// --> A
	printf("%c\n", 0101);
	// --> A
	printf("%c\n", 0x41);
	// --> A
	printf("%c\n", 65);
	// --> A
```

- if you use a larger number than fits within a byte as an argument for the `%c`
  conversion, the higher bits are trimmed.  The rule here is that the `int`
  argument is converted within `printf` to `unsigned char` (not just `char`!),
  then printed as a character (= letter).  More on integer conversion in
  upcoming lectures.  See also
#module numbers.md Numbers
  on why you never pass a `char` nor `short` to a variadic function.
	- also note the existence of `h` and `hh` modifiers.  See the printf()
	  man page for more information.

```C
	printf("%c\n", 65 + 256 + 256 + 256 * 100);
	// --> still prints A
```

- assignment is also an expression, meaning it has a value of the result, so the
  following is legal and all variables `a`, `b`, and `c` will be initialized
  with 13
```C
	int a, b, c;
	a = b = c = 13;
```

### :wrench: Task: print ASCII table

Print ASCII table with hexadecimal values like on in the ascii(7) man page
https://man.openbsd.org/ascii except for non-printable characters print `NP`
(non-printable).

To determine whether a character is printable you can use the `isprint()`
function.

Use just `while` and `if` (without `else`).

Sample output:
```
00 NP	01 NP	02 NP	03 NP	04 NP	05 NP	06 NP	07 NP	
08 NP	09 NP	0a NP	0b NP	0c NP	0d NP	0e NP	0f NP	
10 NP	11 NP	12 NP	13 NP	14 NP	15 NP	16 NP	17 NP	
18 NP	19 NP	1a NP	1b NP	1c NP	1d NP	1e NP	1f NP	
20  	21 !	22 "	23 #	24 $	25 %	26 &	27 '	
28 (	29 )	2a *	2b +	2c ,	2d -	2e .	2f /	
30 0	31 1	32 2	33 3	34 4	35 5	36 6	37 7	
38 8	39 9	3a :	3b ;	3c <	3d =	3e >	3f ?	
40 @	41 A	42 B	43 C	44 D	45 E	46 F	47 G	
48 H	49 I	4a J	4b K	4c L	4d M	4e N	4f O	
50 P	51 Q	52 R	53 S	54 T	55 U	56 V	57 W	
58 X	59 Y	5a Z	5b [	5c \	5d ]	5e ^	5f _	
60 `	61 a	62 b	63 c	64 d	65 e	66 f	67 g	
68 h	69 i	6a j	6b k	6c l	6d m	6e n	6f o	
70 p	71 q	72 r	73 s	74 t	75 u	76 v	77 w	
78 x	79 y	7a z	7b {	7c |	7d }	7e ~	7f NP	

```

Solution: #source ascii-hex.c
