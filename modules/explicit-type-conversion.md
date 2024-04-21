# Explicit type conversion

We already saw an implicit conversion when working with integer types, see the
#module arithmetic-type-conversions.md module on conversions
which also mentions the 6.3 spec section with all the details.

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

(C99, 6.3.2.3, 7)

> A pointer to an object or incomplete type may be converted to a pointer to a
> different object or incomplete type.  If the resulting pointer is not
> correctly aligned for the pointed-to type, the behavior is undefined.
> Otherwise, when converted back again, the result shall compare equal to the
> original pointer.

This will be especially handy for pointers to structures.  See
#module structure-casting.md structure casting
for more information.

You can always cast explicitly but it depends on what will be done with the
result.  For example, on some architectures, you cannot access improperly
unaligned objects.  The following example is from a SPARC machine.

```
$ isainfo
sparcv9 sparc

$ cat main.c
#include <stdio.h>

int
main(void)
{
        char *s = "hello, world, hello, world";
        long long int *p = (long long int *)(s + 1);

        printf("%lld\n", *p);
}

$ gcc main.c
$ ./a.out
Bus Error (core dumped)
```

#source bus-error.c

Now see the following code and figure out what is going to happen.

:wrench:
#source ptr-cast.c

Note that `void *` is a special pointer that cannot be dereferenced.  You can
always assign any pointer to a `(void *)` pointer without any need for casting,
and you can also assign any `(void *)` pointer to any other pointer without any
need for casting.  These assignments are **guaranteed to not lose any
information**.

```C
int i = 99;
void *p = &i;
int *pi = p;

printf("%d\n", *pi);	// will print 99
printf("%d\n", *p);	// dereferencing (void *), will error out when compiled
```

:wrench: Verify that a staticly allocated 2D array is stored in one piece of
memory, row by row.

Hint: you need to recast a 2D array to a 1D array, then print it as a
single row.  There are a few different ways to do it.  Do not look at the
solution until you write your own code.

```C
int a[5][5] = { ... };
// ...
```

#solution 2d-static-array-as-1d.c
