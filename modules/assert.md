## Asserts

- assert(3)
  - basic implementation of assert, provides the run-time condition checking
  - `#define NDEBUG` disables it.  Check the C spec for more information.
  - you need `<assert.h>`
  - `assert(0)` is of common use to bail out and to know where it did

Task: write a custom `assert`() macro that prints the line and file information
(using `__LINE__`, `__FILE__` pre-defined macros) and exits.

#source assert.c
#source my-assert.c

- there is also `#error` pre-processor pragma that can be used to fail during
  the compilation phase

- there is `static_assert()` that is evaluated during compile time however this
  is available only in the C++0x standard
  - it can be handy for things (this is rather a hack) like:

```C
int i;

static_assert(sizeof (void *) >= sizeof (i));
foo((void *) i);
```

- in C99 we can use an array indexing with ternary operator as a check

#source static_assert.c

- to see how it works, run it through the pre-processor (use the `-E` compiler
  option or run `cpp` on the source file)
