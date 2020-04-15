# :wrench: task: offsetof

Write a macro (or start with a function with hardcoded values) that will print
the offset of the specified member of a given structure.

      offsetof(struct X, a)

Hint: exploit the fact that pointer can be assigned an integer (0) + use pointer
arithmetics

Note: `offsetof()` is a standard macro available since ANSI C via `stddef.h`.

:key: code: #source offsetof.c
