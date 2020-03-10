# More on functions/arrays

## variable length array (VLA)
  - automatically allocated based on a variable value.  Only for local
    variables, not globals. Same warning applies w.r.t. array size and stack
    growth as with fixed width arrays.
```C
	void fn(int n, int m)
	{
	    int a[n + m];
	    ...
	}
```
  - :eyes: [array-variable-length.c](/src/array-variable-length.c)
  
## K&R

history: you may still see in very old code: K&R definition with
    types of arguments on separate line(s):
```C
    int
    foo(a, b)
    int a; int b;
    {
	      /* body */
    }
```

some compilers have dropped the support for K&R definitions or will drop
    soon

## variable shadowing

  - :eyes: [shadow.c](/src/shadow.c), [shadow-block.c](/src/shadow-block.c)

  - if the function is declared `static`, it is visible only from the same
    object file

    - static variables: retain value across function calls
    - yes, the word `static` is overloaded in C

## variable number of arguments

  - functions can have variable number of arguments of different types (more on
    that later)
    - the three dots is called *ellipsis*
```
    void func(fmt, ...);
```

   - the first argument usually describes the rest of arguments in some way
      - usually it is a format string.  It could possibly be an argument
	count if they were of the same type however in that case they
	would probably be passed as an pointer (we will get to pointers
	in a later class).

## Function is not object

Like array, function is not a first class object (i.e. no "functor" like in
functional languages)
  - that said, there are pointers to functions (more on these later)
