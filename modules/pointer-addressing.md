# Pointer addressing

We alread know that as with arrays, it is possible to subscript pointers:

```C
int a[10];
int *p = a;

p[0] = ...
```

This just goes directly from the standard: `p[x]` is equivalent to `*(p + x)`.
And remember that incrementing a pointer or an array expression goes by
increments of the element type size.

```C
int a[2] = { 1, 222 };

/* Will print 222. */
printf("%d\n", *(a + 1));
```
