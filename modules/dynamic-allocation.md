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
#define	ARRLEN	20
int *p;

if ((p = malloc(ARRLEN * sizeof (int))) == NULL)
	err(1, "malloc");
p[0] = 99;
p[ARRLEN - 1] = 77;
```

The prototype for `malloc` is as follows:

```C
void *malloc(size_t size);
```

Note that as `malloc` returns `void *`, there is no need to explicitly type its
result when assigned to a pointer.  That is, do not use:

```C
int *p;

p = (int *)malloc(16);
```

See `man malloc` for more memory allocation related functions.
