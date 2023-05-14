# Unions

- Unions resemble structures but they have a different semantics.
	- Unions store its members in the same memory location.
	- This allows for different "views" of the same data.
- They are usually combined with structures.
- Handy for efficient data storage or HW programming.

Consider this declaration:

```C
union foo {
	unsigned short i; // 2 bytes
	struct {
		unsigned char low;
		unsigned char high;
	} bytes;
};
```

- The `sizeof(union foo)` will be that of its largest member.
- Modify a value of `i` and it will be reflected in the low/high values because
  `i` and `bytes` share the same location

```
		0             high memory addresses
		+-------------+
		|      i      |
		+-------------+
		| low  | high |
                +-------------+
```

- Union can be part of a structure, #source union-in-struct.c
  and vice versa #source struct-in-union.c
- Union can be "anonymous" (e.g. no name inside of a structure), however this is
  non-standard just like for structures.

:wrench: Use the above declaration to find out if the program is running on a
big or little endian system (least significant byte is stored on lowest
address).  The program will print either "big endian" or "little endian" to the
standard output.

#solution union-lowhigh.c

:wrench: Take the binary tree implementation and convert it to use a union to
store the data.
