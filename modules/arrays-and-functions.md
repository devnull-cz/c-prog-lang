# Arrays and functions

An array in C is not a *basic type*, rather it is an aggregation of elements.
More specifically, it is an *array type*, one of the *derived types* constructed
from other types.  An array may be also called an *aggregate type*, see
#module 99-standard.md C99 spec 6.2.5 Types
for more information.

An array **cannot be returned from a function**.  A pointer to an array can be
but more on that later.

Not allowing to return an array is done for efficiency as copying the whole
array (by value) would be too expensive.

- Watch for array sizes if used within functions.
- Arrays as a local variable may significantly increase the stack size (and a
  stack size is limited in threaded environments).

#source func-large-array.c

The following may or may not happen in your environment:

```
$ cc func-large-array.c
$ ./a.out
Segmentation fault: 11
```
