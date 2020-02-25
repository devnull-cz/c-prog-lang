## conversion

- all of these are equal:
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
  argument is converted to `unsigned char`, then printed as a character.  More
  on integer conversion in upcoming lectures.

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
