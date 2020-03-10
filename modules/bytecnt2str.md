## byte count to human readable string

 write function to convert `uint64_t` to human readable count
  (binary - see https://en.wikipedia.org/wiki/Orders_of_magnitude_(data) or
  https://en.wikipedia.org/wiki/Mebibyte, e.g. MiB as mebibyte, etc.) and print
  it to standard output

```C
  void bytecnt2str(uint64_t num);
```

  - use character array to represent the magnitude letters and perform
    the lookup based on the actual magnitude
  - if there is a remainder, write a '+' following the number
  - write the output in single `printf()` (use [ternary operator](/modules/ternary-operator.md) for the remainder)

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

