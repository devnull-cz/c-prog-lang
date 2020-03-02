# Array Intro

You define an array like this `int array[*N*]`, for example:

```C
int array[5];
```

The integer value in `[]` specifies number of array elements.

- an array *subscript* always starts from `0` and ends with `n - 1`
- a subscript may be any integer expression

So, `int array[3]` members will be accessible as `a[0]` .. `a[2]`

- the 0 is used there for better work with pointers and efficiency for array
  access

- what is not possible to do with arrays in C (limitations are important
  knowledge):

	- associative arrays
	- array subscripts returning a sub-array (like found e.g. in Python)

- as with integer and floating point variables, we may initialize an array when
  during its definition.  The individual numbers are known as *initializers*.

```C
short array[3] = { 1, 2, 3 };
```

If the array size is omitted the compiler will compute the size from the the
number of initializers.  So, you can just do the following.

Note that if you need your array to contain only those elements in the
initialization, then omitting the array size is the way to go to avoid errors as
in changing the initialization and forgetting to update the array size.

```C
short array[] = { 1, 2, 3 };
```


- the `sizeof` operator on array always gets **the array size in bytes**.  It
  will **not** get size of the array in elements.

  	- to get the number of elements in an array, you must divide the array
	  size in bytes by the size of its element.

```C
int a[5];

printf("Elements in array: %zu\n", sizeof (a) / sizeof (a[0]));
```

The above is the correct approach that is immune to changing the array
declaration (i.e. the type of elements).  Do not use the following:

```C
    sizeof (array) / sizeof (int)
```

- arrays defined as shown are not dynamic and **can not** be resized

	- try to perform out-of-bounds access. What is the threshold for
	  behavior change on your system ?
	- why is it not faulting for the one-off error?

:eyes: [array-out-of-bounds.c](/src/array-out-of-bounds.c)


```
$ ./a.out
Number of array elements: 1024
One-off error (using index 1024)... OK
Assigning to index 4096... Segmentation Fault
```

You do not need to initialize all elements.  With such type of an
initialization, you always start in the beginning, and there may be no gaps:

```C
  short array[4] = { 1, 2, 3 };
```

- elements not explicitly initalized are set to `0` so the value of `array[3]`
  will be initialized to `0`

	- i.e. `int array[100] = { 0 };` will have all values set to 0

        - the initialization is done by a compiler

		  - using `= {}` is not allowed by the C specification (allowed
		    in C++) but generally accepted.  Not with `-Wpedantic`
		    though:

```
cc -Wpedantic test.c
test.c:1:13: warning: use of GNU empty initializer extension
      [-Wgnu-empty-initializer]
int a[10] = {};
	    ^
1 warning generated.
```

Note: **global variables are always zeroized.**

There is *partial array initialization* where the *initializers* are called
*designated initializers* in the C spec:

  char array[128] = { [0] = 'A', [2] = 'f', [4] = 'o', [6] = 'o' };

- index is in the square brackets
- the `[index]` is known as a *designator*.  Inreasing ordering is not required
  but expected.
- the rest of items will be initialized to zeroes
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

:eyes: [array-designated-initializers.c](/src/array-designated-initializers.c)

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
int array[3];

array[0] = 1;
array[1] = 2;
array[2] = array[3] = 3;
// ...
```

- you cannot assign array into array - has to be done item by item
	- likewise for comparison

- arrays cannot be declared as empty (`int a[0]`)

	- this is explicitly forbidden by the standard
	  [C99](/modules/c99-standard.md) 6.7.5.2 Array declarators)
	- GCC accepts that though.  Do not use it like that.

:eyes: [empty-array.c](/src/empty-array.c)

This does not really makes sense.

```
$ gcc empty-array.c
$ ./a.out
4
```

Not allowing empty arrays means that `sizeof() / sizeof(a[0])` construction is
always correct to compute a number of array elements.  Plus, the compiler does
not do any array access when computing sizeof(a[0]) as the expression is not
evaluated (see lecture 02 on the `sizeof` operator), the compiler only uses the
argument to determine the size.
