# heap/dynamic allocation: malloc()/free()

The memory automatically allocated for local variables and function parameters
is allocated in an area called a *stack*. There is an area called a *heap* to
allocate memory that lasts after the function returns. This is also called
*dynamic allocation*.

The allocator in the standard C library offers the
`malloc`()/`calloc`()/`free`()/...  APIs for heap allocation.

:heavy\_exclamation\_mark: The `malloc`/`calloc` functions return a pointer to a
memory area of a specified size or a null pointer if the allocation failed -
always check that!  (even on Linux where it seems it can never fail - to be
prepared for change in a configuration and also for portability to systems with
more conservative memory allocation).

```C
#define	NUM_ELEMS	20
int *p;

if ((p = malloc(NUM_ELEMS * sizeof (int))) == NULL)
	err(1, "malloc");
p[0] = 99;
p[NUM_ELEMS - 1] = 77;
```

The prototype for `malloc` is as follows:

```C
void *malloc(size_t size);
```

Note that as `malloc` returns `void *`, there is no need to explicitly type its
result when assigned to a pointer, see
#module explicit-type-conversion.md Explicit type conversion.
That is, do not use:

```C
int *p;

p = (int *)malloc(16);	// unnecessary cast
```

See `man malloc` for more memory allocation related functions.

The C runtime does not have a garbage collector so all heap allocated memory
has to be explicitly freed via `free`() after it is no longer needed.

:wrench: write a program that takes at least 2 arguments.  First argument
specifies a dimension of an array of `int`s, the rest are the `int`s to fill
out the array.  To allocate memory for the array, use `malloc`.  When filling
out the array , ignore extra arguments.  If you have less arguments, use zero
for the remaining array elements.  At the end, print out the array.  To convert
a string to an integer, use `atoi` and assume numbers are correctly entered.

```
./a.out 10 1 2 3 7 8 999 7 7 7 9 9 9 10 11
1 2 3 7 8 999 7 7 7 9 
```

#solution allocate-and-fill-out-array.c
