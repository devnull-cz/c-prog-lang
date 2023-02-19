# Preprocessor

- defines:
  - basic defines: `#define FOO` or `#define FOO 1`
- includes:
  - `#include "foo.h"` (start in current directory and then continue the
    search in system paths) or `#include <foo/bar.h>` (just system paths)
    - some compilers display the include search paths (e.g. clang with `-v`)
    - use the `-I` compiler option to add search paths to the list
- conditional compilation:
  - `#if`, `#ifdef`, `#ifndef`, `#else`, `#endif`
    - `#if` can be used with expressions:
      ```C
      #if MY_VERS >= 42
      ...
      #endif
      ```
  - also useful for *header guards* (to avoid including same header file
    multiple times)
    ```C
    #ifndef FOO_H
    #define FOO_H
    ...
    #endif
    ```
  - can be used e.g. for debug code:
    ```C
    #ifdef DEBUG
    ... // here can be anything (where valid):
        // statements, variable declarations/definitions, function definitions, ...
    #endif
    ```
    - then the compiler can be run with `-DDEBUG` to enable the code
- macros: for more complicated code snippets, e.g. `#define IS_ZERO(a)  a == 0`
  - the argument will be replaced with whatever is given
  - use parens for `#define` to prevent problems with macro expansion
    - `#define	X	(1 + 1)`
    - same for more complicated macros:
      `#define MUL(a, b)  ((a) * (b))`

#source mul.c

To see the result of running preprocessor on your code, use `cpp` or
the `-E` option of the compiler.

### :wrench: Task: reimplement fahr-to-cent.c using defines instead of literal numbers

#solution fahr-to-cent_defines.c
