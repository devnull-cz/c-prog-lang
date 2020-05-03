# Building with a specific C specification version

If you want to make sure your code is built following a concrete C version, it
has two parts:

- you must request the version in your C code
- you need an implementation (compiler, linker, ...) that supports the version
  you want

## Limiting your code to specific C spec version

In [C89](http://port70.net/~nsz/c/c89/c89-draft.html), there was no
`__STDC_VERSION__` macro (note there are two underscores both leading and
terminating the macro).  In the [Normative Addendum
1](http://port70.net/~nsz/c/c89/c94_na1.html) for C89 from 1994, the macro was
defined with a value of `199409L`.  In the [C99
specification](http://port70.net/~nsz/c/c99/n1256.pdf) (there is also a [handy
txt only version](http://port70.net/~nsz/c/c99/n1256.txt), the macro has a value
of `199901L`.

So, if you want your compiler to use a minimal or a specific C version, work
with the macro and `#ifdef` and `#error` preprocessor directives.

```C
#ifndef __STDC_VERSION__
#error "__STDC_VERSION__ not defined.  C99 compiler or greater required."
#else
#if __STDC_VERSION__ < 199901L
#error "C99 compiler or greater required."
#endif
#endif
```

#source check-c-version.c
#source request-c99.c

## Compiler version

In the [1997: Single UNIX Specification (SUS) version
2](https://en.wikipedia.org/wiki/Single_UNIX_Specification#1997:_Single_UNIX_Specification_version_2),
with systems supporting that version as UNIX98, the compiler binary supporting
C89 had to be named `c89`.  You can [search SUS ver 2
here](https://pubs.opengroup.org/onlinepubs/7990989775/), and type `c89`.

In
[POSIX:2004](https://en.wikipedia.org/wiki/Single_UNIX_Specification#2004:_POSIX:2004),
which is SUS ver 3 with updates, the C compiler binary supporting C99 standard
had to be named `c99`.  The [latest SUS
version](https://pubs.opengroup.org/onlinepubs/9699919799/) (as of May, 2020)
still defines `c99`.  I expect the future SUS versions with require `c11` binary
to support C11 standard.

TODO: c89 on macOS, gcc -std=c99, c89 on macOS with `_Bool`
