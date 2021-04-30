# The boolean type

There is a new `_Bool` type as of C99.  Put `0` as false, and a non-zero (stick
to `1` though) as a true value.

The keyword name starts with an underscore as such keywords were always reserved
in C while `bool`, `true`, nor `false` never were.  So, some older code might
actually use those names so if C99 just put those in the language, it would have
broken the code and that is generally not acceptable in C.

If you are certain that neither `bool`, `true`, nor `false` are used in the code
on its own, you can use those macros if you include `<stdbool.h>`.

In that case, the macro `bool` expands to `_Bool`.  `true` expands to `1` and
`false` to `0` and both may be also used in `#if` preprocessing directives.

See C99 section 7.16 for more information.

See #source bool.c
