# More on functions/arrays

## Variable length array (VLA)

- Automatically allocated based on a variable value.  Only for local variables,
  not globals.  Same warning applies w.r.t. array size and stack growth as with
  fixed width arrays.

```C
void fn(int n, int m)
{
    int a[n + m];
    ...
}
```
- #source array-variable-length.c

- :heavy\_exclamation\_mark: Note that it generates more code which might be
  avoided with a choosing a reasonable constant, if possible.  Also see [a rant
  from Linus](https://lkml.org/lkml/2018/3/7/621).

## K&R

History: you may still see in very old code: K&R
([Kernighan](https://en.wikipedia.org/wiki/Brian_Kernighan) and
[Ritchie](https://en.wikipedia.org/wiki/Dennis_Ritchie))
definition with types of arguments on separate line(s):

```C
int
foo(a, b)
int a; int b;
{
	/* body */
}
```

Some compilers have dropped the support for K&R definitions or will drop it
soon.

## Function is not an object

Like an array, function is not a first class object (i.e. no "functor" like in
functional languages).

- That said, there are pointers to functions (more on these later).
