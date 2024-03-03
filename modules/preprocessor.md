# Preprocessor

The main purposes of the preprocessor are: string replacement, file inclusion,
general code template expansion (macros), and managing conditional compilation.

- String replacement:
  - Basic defines: `#define FOO` or `#define FOO 1`
  - A define without a value is still meaningful for conditional compilation.

- Including files:
  - `#include "foo.h"` (start in current directory and then continue the
    search in system paths) or `#include <foo/bar.h>` (just system paths)
    - Some compilers display the include search paths (e.g. clang with `-v`).
    - Use the `-I` compiler option to add search paths to the list.

- Conditional compilation:
  - `#if`, `#ifdef`, `#ifndef`, `#else`, `#endif`
    - `#if` can be used with expressions:
      ```C
      #if MY_VERS >= 42
      ...
      #endif
      ```
  - Also useful for *header guards* (to avoid including same header file
    multiple times):
    ```C
    #ifndef FOO_H
    #define FOO_H
    ...
    #endif
    ```
  - Can be used e.g. for debug code:
    ```C
    #ifdef DEBUG
    ... // here can be anything (where valid):
        // statements, variable declarations/definitions, function definitions, ...
    #endif
    ```
    - Then the compiler can be run with `-DDEBUG` to enable the code.

- Macros: for more complicated code snippets, e.g. `#define IS_ZERO(a)  a == 0`
  - The argument will be replaced with whatever is given.
  - Use parens for `#define` to prevent problems with macro expansion:

    - `#define	X	(1 + 1)`
    - Same for more complicated macros:
      `#define MUL(a, b)  ((a) * (b))`

#source mul.c

To see the result of running preprocessor on your code, use `cpp` or
the `-E` option of the compiler.

### :wrench: Task: reimplement fahr-to-cent.c using defines instead of literal numbers

#solution fahr-to-cent_defines.c
