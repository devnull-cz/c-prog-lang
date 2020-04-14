# Explicit type conversion

We already saw an implicit conversion when working with integer types.

Casting is an explicit type conversion:

```C
(type_name)expression;

int i = 13;
long l = (long)i;		// Just an example.  The casting not needed in this
				// case, the implicit integer conversion would
				// work fine.
```

Casting is used to avoid compiler warnings as a sort of a hint to the compiler
that you know what you are doing.

#source cast-double.c

Explicit cast for pointers of different types works:

(C2011, 6.3.2.3/7)

> A pointer to an object type may be converted to a pointer to a different
> object type.  If the resulting pointer is not correctly aligned for the
> referenced type, the behavior is undefined.  Otherwise, when converted back
> again, the result shall compare equal to the original pointer.

This will be esp. handy for pointers to structures.

The cast itself is not a problem, it depends on what will be done with the
result.

#source ptr-cast.c

`void *` is a special pointer that cannot be dereferenced.  You can always
assign any pointer to a `(void *)` pointer without any need for casting, and you
can also assign any `(void *)` pointer to any other pointer without any need for
casting.  These assignments are **guaranteed to not lose any information**.

```C
int i = 99;
void *p = &i;
int *pi = p;

printf("%d\n", *pi);	// will print 99
printf("%d\n", *p);	// will error out when compiled
```

Verify that a staticly allocated 2D array is stored in one piece of memory, row
by row.  Hint: you need to recast a 2D array to a 1D array, then print it as a
single row.  There are a few different ways to do it.  Do not look at the
solution until you write your own code.

```C
int a[5][5] = { ... };
// ...
```

#source 2d-static-array-as-1d.c
