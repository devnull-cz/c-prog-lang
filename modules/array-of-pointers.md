# Array of pointers

See also what we already know about
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

#source array-of-ptrs.c
