# Arrays and functions

Arrays in C are not a first class object, rather it is an aggregation of
elements.  An array is one type of an *aggregate type*, see
#module c99-standard.md C99 spec 6.2.5 Types (paragraph 21)
for more information.

An array **cannot be returned from a function**.  A pointer to an array can be
but more on that later.

Not allowing to return an array is done for efficiency as copying the whole
array (by value) would be too expensive.

- watch for size of an array as a local variable in a function
- arrays as local variable may significantly increase the stack size (and a
  stack size is limited in threaded environments)

#source func-large-array.c

The following may or may not happen in your environment:

```
$ cc func-large-array.c
$ ./a.out
Segmentation fault: 11
```
