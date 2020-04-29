# The `const` keyword

`const` is a *qualifier* that may be applied to the declaration of any variable.
It specifies its value cannot be changed.  If you apply `const` to an array, the
array elements cannot be modified.

You can initialize the variable declared with the `const` qualifier.

#source const.c

Using `const` will not really make the storage constant, you just cannot use
that variable for an assignment to the storage.

```C
int i = 'c';
int const *p2 = &i;

// illegal
*p2 = 'x';
// ok
i = 'x';
```

#source const-not-really-a-const.c

It also depends where you apply the `const` keyword.

```C
char const *s1;		// s1 is a pointer to const char
const char *s1;		// same as above
char *const s2;		// s2 is a const pointer to a char

*s1 = 'c';		// illegal
s1 = NULL;		// legal

s2 = NULL;		// illegal
*s2 = 'a';		// legal
```

#source const-and-pointers.c

Using `const` can get a bit confusing.  It is mostly used for pointer arguments
to constant memory to specify that an array will not be changed in the function.
For example, string functions:

```C
size_t strlen(const char *s);
char *strncpy(char *dest, const char *src, size_t n);
...
```

:wrench: `const`

The following is a `const` pointer to a `const` character.  So, you can neither
do `*p = ...` nor `p = ...`.  Verify.

```C
const char *const p;
```
