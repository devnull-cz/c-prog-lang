# Arrays as function arguments

:heavy\_exclamation\_mark: When an array name is passed to a function, what is
actually passed is the **address of the first element** and the local variable
representing the argument within the function is of a type of **pointer to the
array element**.  So, you can just declare the argument as an pointer to an
element type and pass in an array name.

The reason for this is that as C can only pass arguments by value, copying array
data to function arguments would be very inefficient.

Even if you declare a function argument as an array, **the argument is always
treated as a pointer**.  The optional array size is accepted but ignored.  Do
not use it as it is only confusing.  See for example *6.9.1 Function
definitions*, paragraph (10) in
#module c99-standard.md C99.

```C
void
myfn(int a[])
{
	/*
	 * 'a' here is a pointer to int, not an array of ints.  So, you can
	 * assign to it, for example (which you cannot do with an array).
	 */
	a = NULL;
}
```

#source array-as-argument.c

Some compilers even notice that the `sizeof` operator is applied on an array
passed into a function and produce a warning about it (clang with
`-Wsizeof-array-argument`).

```
$ clang -Wsizeof-array-argument array-as-argument.c
array-as-argument.c:15:25: warning: sizeof on array function parameter will
    return size of 'char *' instead of 'char [20]' [-Wsizeof-array-argument]
        printf("%zu\n", sizeof (a));
                               ^
array-as-argument.c:12:11: note: declared here
myfn(char a[20])
          ^
1 warning generated.
```

However, it only applies to the first array dimension.  That is, a
multi-dimensional array is just a 1-dimensional array of elements that are of an
array type.  Note that **we are getting ahead of ourselves a little bit here**,
more on that will be later, especially on reading more complex declarations.

#source passing-arrays.c

```
$ cc src/passing-arrays.c
src/passing-arrays.c:14:14: warning: incompatible pointer types passing 'int (*)[3]' to parameter of
      type 'int (*)[2]' [-Wincompatible-pointer-types]
        myfn(p2);       // will trigger a warning
             ^~
src/passing-arrays.c:2:10: note: passing argument to parameter 'a' here
myfn(int a[2][2])
         ^
1 warning generated.
```
