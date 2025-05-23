# Incomplete types

An *incomplete type* is a type that describes an object but lacks information
needed to determine its size.  You cannot declare objects using such types as
the lack of the size prevents to allocated memory for them on the stack or heap.

```
$ cat main.c
struct x a;	/* declaring a variable using a structure of an unknown size */

int
main(void)
{
}

$ cc main.c
main.c:1:10: error: tentative definition has type 'struct x' that is never
      completed
struct x a;
         ^
main.c:1:8: note: forward declaration of 'struct x'
struct x a;
       ^
1 error generated.
```

The `x` structure could be completed, for all declarations of that type, by
declaring the same structure tag with its defining content later in the same
scope.  We could only *forward declare* the structure though (that is, no
defining any object of that structure type).

As we do not need to know the size of the `x` structure, the following code
compiles.

```
$ cat main.c
struct x;	/* this is called forward declaration */

int
main(void)
{
}

$ cc main.c
$ echo $?
0
```

BTW, the `void` type is an incomplete type that can be never completed.  So, you
cannot declare a variable of type `void`.

```C
$ cat main.c
int
main(void)
{
	void x;
}

$ cc main.c
main.c:4:7: error: variable has incomplete type 'void'
        void x;
             ^
1 error generated.
```

However, you can always declare and work with a pointer to an incomplete type
(all structures are always aligned to the same byte boundary).  The following
will compile and run fine.

```C
#include <stdio.h>

struct x;

struct x *
myfn(struct x *p)
{
        return (p);
}

int
main(void)
{
        myfn(NULL);
}
```

This feature of the C language can be used to represent opaque handles, and
those can be used to solve the
#module transparent-handles.md problem with transparent handles
.
