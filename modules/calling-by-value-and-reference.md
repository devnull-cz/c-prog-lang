# Calling by value vs calling by reference

In C, function arguments are always passed by value.  To change a value of an
argument, thus emulating a calling by reference, you need to pass pointers.
That means, you pass a pointer by value so that you know what piece of memory to
modify.

The following will **not** do what one might naively assume it would.  What you
actually swap are values on a stack or in registers while the original objects
were left untouched.

```
int
swap(int a, int b)
{
	int n = a;

	a = b;
	b = n;
}
```

#source swap-by-value.c

:wrench: modify the code above so that `swap`() that actually swaps the values
of the two `int`s.  Hint: aside from the *dererence* operator `*`, you will also
need the *address-of* operator `&` - see
#module pointers.md pointer basics

#solution swap-by-reference.c
