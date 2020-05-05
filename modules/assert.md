## Asserts

- assert(3)
  - basic implementation of assert, provides run-time condition checking
  - `#define NDEBUG` disables it normally (ie. in the real life the assert
    macro is more complicated.
  - you need `<assert.h>`
  - assert(0) is of common use to bail out and to know where it did

Task: write custom assert() macro that prints the line and file information
      (using `__LINE__`, `__FILE__` pre-defined macros) and exits
#source assert.c

- there is also #error pre-processor pragma that can be used to fail during
  compilation phase

- there is static_assert() that is evaluated during compile time however this is
  available only in C++0x
  - it can be handy for things (this is rather a hack) like:
```C
    int i;

    static_assert(sizeof(void *) >= sizeof i);
    foo((void *) i);
```
  - in C99 we can use a array indexing with ternary operator as a check

#source static_assert.c
