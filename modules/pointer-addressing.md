# Pointer addressing

We already know that as with arrays, it is possible to use the array subscript
operator `[]` on pointers, too:

```C
int a[10];
int *p = a;

p[0] = ...
```

That goes directly from the standard:

>`p[x]` is equivalent to `*(p + x)`.

Remember that incrementing a pointer or an array expression goes by increments
of the element type size.

```C
int a[2] = { 1, 222 };

/* Will print 222. */
printf("%d\n", *(a + 1));
```
