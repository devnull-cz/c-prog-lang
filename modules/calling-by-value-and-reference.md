# Calling by value vs calling by reference

In C, function arguments are always passed by value.  To change a value of an
argument, thus emulating a calling by reference, you need to pass pointers.

So, the following will **not** do what we might naively assume it would:

```
int
swap(int a, int b)
{
	int n = a;

	a = b;
	b = n;
}
```

[swap-by-value.c](https://github.com/devnull-cz/c-prog-lang/blob/master/src/swap-by-value.c)

:wrench: modify the code above so that `swap`() that actually swaps the values
of the two `int`s.  Hint: aside from the *dererence* operator `*`, you will also
need the *address-of* operator `&` (see [pointer basics](https://github.com/devnull-cz/c-prog-lang/blob/master/modules/pointers.md).

:eyes: [swap-by-reference.c](https://github.com/devnull-cz/c-prog-lang/blob/master/src/swap-by-reference.c)
