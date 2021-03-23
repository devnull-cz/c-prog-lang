# More on functions/arrays

## variable length array (VLA)
- automatically allocated based on a variable value.  Only for local variables,
  not globals. Same warning applies w.r.t. array size and stack growth as with
  fixed width arrays.

```C
	void fn(int n, int m)
	{
	    int a[n + m];
	    ...
	}
```
- #source array-variable-length.c

- :heavy\_exclamation\_mark: note that it generates more code which might be
  avoided with a choosing a reasonable constant, if possible.  Also see [a rant
  from Linus](https://lkml.org/lkml/2018/3/7/621).

## K&R

history: you may still see in very old code: K&R definition with types of
arguments on separate line(s):

```C
int
foo(a, b)
int a; int b;
{
      /* body */
}
```

Some compilers have dropped the support for K&R definitions or will drop soon.

## Variable shadowing

- every identifier has its *scope*

- the scope of a name is the part of the program within which the name can be
  used.

- for example, we can declare a variable `int i` in the `main` function, and as
  well as in another function.  Those two variables reference different storage.

- for now, we only care about two types of scope - a file, and a block.

- when declaring a variable within the outer block of the function, its scope is
  from the variable declaration to the end of the function block.

- note that a block is used in multiple constructs in C, e.g. `while`, `for`,
  etc.

- #source shadow.c
#source shadow-block.c

## Function is not object

Like an array, function is not a first class object (i.e. no "functor" like in
functional languages).

  - that said, there are pointers to functions (more on these later)
