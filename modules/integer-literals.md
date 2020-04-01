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
  argument is converted to `unsigned char` (not just `char`!), then printed as a
  character (= letter).  More on integer conversion in upcoming lectures.  See
  also
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

To determine whether a character is printable you can use the isprint()
function.

Use just `while` and `if` (without `else`).

Solution: #source ascii-hex.c
