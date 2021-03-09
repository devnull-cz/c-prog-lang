# Preprocessor

  - defines:
    - basic defines: `#define FOO` or `#define FOO 1`
  - includes:
    - `#include <foo/bar.h>` or `#include "foo.h"`
  - conditional compilation:
    - `#if`, `#ifdef`, `#ifndef`, `#else`, `#endif`
    - also useful for header guards (to avoid including same header file
      multiple times)
      ```C
      #ifndef FOO_H
      #define FOO_H
      ...
      #endif
      ```
  - use parens for `#define` to prevent problems with macro expansion
    - `#define	X	(1 + 1)`

To see the result of running preprocessor on your code, use `cpp` or
the `-E` option of the compiler.

### :wrench: Task: reimplement fahr-to-cent.c using defines instead of literal numbers
  - solution: `fahr-to-cent_defines.c`
