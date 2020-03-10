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

  solution: [range-check.c](/src/range-check.c)

  - on Unix systems one would use `ssize_t` for the offset which is signed
    integer type of the same size as `size_t` (this is not part of C99 but
    POSIX)

  - also, implement set of test values in `main()` using array
