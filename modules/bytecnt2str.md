## byte count to human readable string

 write function to convert `uint64_t` to human readable count
  (binary - see https://en.wikipedia.org/wiki/Orders\_of\_magnitude\_(data) or
  https://en.wikipedia.org/wiki/Mebibyte, e.g. MiB as mebibyte, etc.) and print
  it to standard output

```C
  void bytecnt2str(uint64_t num);
```

  - use character array to represent the magnitude letters and perform
    the lookup based on the actual magnitude
  - if there is a remainder, write a '+' following the number
  - write the output in single printf() (use ternary operator for the remainder)

  - example inputs/outputs:
```
1024		1 KiB
1025		1+ KiB
2047		1+ KiB
2048		2 KiB
2049		2+ KiB
5242880		5 MiB
```
  solution: [bytecnt2str.c](src/bytecnt2str.c)

## Offset checker

write a function that will have this prototype:

```C
  bool check(long off, size_t size, size_t limit);
```
  - the `bool` type exists since C99, use the `stdbool.h` include
  - that will check if the arguments are valid for accessing part of file (no
    operations will be done, just the check) of size 'size' starting from offset
    'off'. The length of the file is given by 'limit'.

```
    |           |         |              |
    0          off     off+size        limit
```

  - try to capture all corner cases of what could go wrong with the values
    and return `false` on failure, `true` on success.

  solution: [range-check.c](src/range-check.c)

  - on Unix systems one would use `ssize_t` for the offset which is signed
    integer type of the same size as `size_t` (this is not part of C99 but
    POSIX)

  - also, implement set of test values in `main()` using array
