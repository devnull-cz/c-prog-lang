# Unions

- similar to structures however have different semantics
	- stores its members in the same memory location
	- allows for different "views" of the same data
- usually combined with structures
- handy for efficient data storage or HW programming

consider this declaration:
```C
union foo {
	unsigned short i; // 2 bytes
	struct {
		unsigned char low;
		unsigned char high;
	} bytes;
};
```
  - the `sizeof(union foo)` will be that of its largest member
  - modify a value of `i` and it will be reflected in the low/high values
    because `i` and `bytes` share the same location

```
		0             high memory addresses
		+-------------+
		|      i      |
		+-------------+
		| low  | high |
                +-------------+
```

- union can be part of a structure, #source union-in-struct.c
  and vice versa #source struct-in-union.c
- union can be "anonymous" (e.g. no name inside of a structure), however this is
  non-standard just like for structures

:wrench: Task: use the above declaration to find out if the program is running
on big or little endian system (least significant byte is stored on lowest
address). The program will print either "big endian" or "little endian" to
standard output.

:key: code: #source union-lowhigh.c
