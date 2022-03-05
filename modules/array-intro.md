# Array Intro

You define an array like this `<element-type> array[<some-number>]`, for
example:

```C
int array[5];
```

The integer value `n` in `[n]` specifies the number of array *elements*.

- an array *subscript* always starts from `0` and ends with `n - 1`
- a subscript may be any integer expression
- the type of array elements is called an *element type*

So, `int array[3]` elements will be accessible as `a[0]` .. `a[2]`, each element
is of type `int`, and therefore you can do e.g. `printf("%d\n", a[2]);`.

- `0` was chosen as the first subscript so that was is easier to work with
  *pointers* and for array access efficiency - we will get to pointers later.

- what is not possible to do with arrays in C (limitations are important
  knowledge):

	- associative arrays
	- array subscripts returning a sub-array (like found e.g. in Python)
	- assigning to an array as a whole

- as with integer and floating point variables, we may initialize an array
  during its definition.  In general, the value for the initialization is known
  as an *initializer*.

```C
short array[3] = { 1, 2, 3 };
```

If the array size is omitted the compiler will compute the size from the the
number of initializers.  So, you can just do the following.

```C
short array[] = { 1, 2, 3 };
char array[] = { 'h', 'e', 'l', 'l', 'o' };
```

Note that if you need your array to contain only the elements from the
initializer, omitting the array size is the way to go to avoid errors as in
changing the initializer while forgetting to update the array size.

- the `sizeof` operator on array always gets **the array size in bytes**.  It
  will **not** get the array size in elements.

  	- to get the number of elements in an array, you must divide the array
	  size in bytes by the size of its element.  Always use `0` subscript,
	  see below on why.

```C
int a[5];

printf("Elements in array: %zu\n", sizeof (a) / sizeof (a[0]));
```

The above is the correct approach that is immune to changing the array
declaration (i.e. the type of elements).  Do not use the following:

```C
    sizeof (array) / sizeof (int)
```

:wrench: Declare an array of `char`s without setting the array size, initialize
the array during declaration (see above), then print each element of the array
on a separate line using a `while` loop.

Arrays introduced so far are not dynamic and **can not** be resized.

- try to perform out-of-bound access. What is the threshold for
  behavior change on your system ?
- why is it not faulting for the one-off error?

#source array-out-of-bounds.c


```
$ ./a.out
Number of array elements: 1024
One-off error (using index 1024)... OK
Assigning to index 4096... Segmentation Fault
```

You can also try to locate where it crashed.  For more information, see
#module debugger.md some info on debugging.

You do not need to initialize all elements.  With such type of an
initialization, you always start from subscript `0`, and there are no gaps:

```C
  short array[4] = { 1, 2, 3 };
```

In the example above, the elements not explicitly initalized are set to `0` so
the value of `array[3]` will be initialized to `0`.

- i.e. `int array[100] = { 0 };` will have all values set to `0`

- the initialization is done by a compiler

- using `= {}` is not allowed by the C specification (allowed in C++) but
  generally accepted.  Not with `-Wpedantic` though:

```
cc -Wpedantic test.c
test.c:1:13: warning: use of GNU empty initializer extension
      [-Wgnu-empty-initializer]
int a[10] = {};
	    ^
1 warning generated.
```

Note: **global variables are always zeroized.**

There is a *partial array initialization* where the *initializers* are called
*designated initializers* in the C spec:
```C
  char array[128] = { [0] = 'A', [2] = 'f', [4] = 'o', [6] = 'o' };
```
- a subscript is in square brackets
- the `[subscript]` is known as a *designator*.  Inreasing ordering is not
  required but expected.
- the rest of elements will be initialized to zero
- if you do not specify the array size, it is taken from the highest designator
  index
- you can combine designators with fixed order initializers, and you always
  start with the next index.  For example:

```C
  /* a[5] is 'e' etc.  a[0]..a[3] are NUL characters (= zero bytes). */
  char a[128] = { [4] = 'h', 'e', 'l', 'l', 'o' };
```

- you cannot specify a repetition or setting multiple elements to the same value
  (there is a gcc extension for that but let's not go there).

#source array-designated-initializers.c

Note the code above mentions a missing `=` as a GCC extension.  With a non-GCC
compiler it does not compile:

```
$ cc array-designated-initializers.c
"array-designated-initializers.c", line 15: syntax error before or at: 'A'
cc: acomp failed for array-designated-initializers.c
```

Once declared, the values cannot be assigned at once.  So, you can only do
things as follows:

```C
int array[4];

array[0] = 1;
array[1] = 2;
array[2] = array[3] = 3;
// ...
```

You cannot assign an array into array - has to be done an element by element.

- likewise for comparison

Arrays cannot be declared as empty (`int a[0]`).

- this is explicitly forbidden by the standard, see
#module c99-standard.md C99
6.7.5.2 Array declarators.
- GCC accepts that though.  Do not use it like that.

#source empty-array.c

This might be a bit confusing though:

```
$ gcc empty-array.c
$ ./a.out
4
0
```

Even if a compiler supports an empty array declaration, `sizeof(a) /
sizeof(a[0])` construction is always correct to compute a number of array
elements.  Plus, remember the compiler does not do any array access when
computing `sizeof(a[0])` as the expression is not evaluated (see
#module sizeof.md the sizeof operator
), the compiler only uses the argument to determine the size.
