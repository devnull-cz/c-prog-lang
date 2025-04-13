# Array of pointers

Remember what we know about
#module program-arguments.md program arguments.

```C
/*
 * [] is of higher precedence than *, so the following means:
 *
 *	 "a is an array of 10 pointers to char"
 */
char *a[10];
```

You could write it as `char *(a[10])` but that would be quite uncommon and is
not recommended.

You can initialize such an array the same way as before.  Remember, a string
literal is internally an array of `char`s, so we can use it to initialize the
following array of `char` pointers (it is the same as if we did `char *p = a`).

```C
char *a[] = { "hello", "world", "!" };
```

Modifying such strings is an undefined operation as they are read-only by the
specification (6.4.5 paragraph 6: *If the program attempts to modify such an
array, the behavior is undefined*).  Code doing so and compiled by GCC or Clang
will crash.

Note that (informative) Annex J in the C99 spec lists modifying a string literal
as a known portability issue.  See *J.2 Undefined behavior* and look for "The
program attempts to modify a string literal".

#source array-of-ptrs.c
