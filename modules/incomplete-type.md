# Incomplete types

An *incomplete type* is a type that describes an object but lacks information
needed to determine its size.

```
$ cat main.c
struct x a;

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

```
$ cat main.c
struct x;

int
main(void)
{
}

$ cc main.c
$ echo $?
0
```

BTW, the `void` type is an incomplete type that can be never completed.

However, you can always declare and work with a pointer to an incomplete type
(all structures are always aligned to the same byte boundary).  The following
will compile and run fine.

```C
#include <stdio.h>

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

This feature of the C language is used to represent opaque handles.
