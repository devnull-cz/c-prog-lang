# Structure bit fields

- sometimes memory is scarce (imagine having to keep millions of big
  structures in memory) and there are members holding integer values that occupy
  just a couple of bytes
  - bit fields can be used to shrink the memory needed

```C
struct foo {
	unsigned int a : 3;
	unsigned int b : 1;
	unsigned int   : 4;
};
```

- the number after the colon specifies the number of bits for given bit field
  - cannot exceed the size of the underlying data type (`unsigned int` in the
    above example)
- cannot use `sizeof` on bitfield

- this is good for implementing network protocol headers or HW registers,
  however the layout of bit fields in C structure is implementation dependent
  - if it needs to match a concrete layout, additional non-standard compiler
    features have to be used (`#pragma`'s etc.)
  - there is no `offsetof()` for bit fields

code: #source bitfield.c

- the integer values will behave as expected, e.g.

```C
unsigned int a : 3;

a = 7;
a++; // will wraparound to 0 since this is unsigned
```
