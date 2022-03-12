# Multidimensional arrays

- multi-dimensional arrays: it is an array of arrays

```C
int a[3][2] = { {0, 1}, {2, 3}, {4, 5} };
```

- `a` is an array of 3 elements.  Each of the element in an array of 2 elements.
  - we read it like that as the operator `[]`, called *array subscripting*, is
    evaluated **left-to-right**.  See
#module operator-precedence.md operator precedence
    for more information.

- to access a given item all elements have to be specified in square brackets.
  i.e. `a[1, 2]` does not work, you have to use `a[1][2]`

- in memory this is stored as consequent individual "lines".  In other words,
  any array, no matter how many dimensions it has, is stored as one piece of
  contiguous memory.

- for 3-D array it looks as follows.  `a` is an array of 2-dimensional arrays:

```C
int a[2][4][3] = {
	{ {1, 2, 3}, {4, 5, 6}, {8, 7, 8}, {9, 1, 9} },
	{ {0, 0, 0}, {1, 1, 1}, {2, 2, 3}, {4, 4, 5} },
};
```

- in memory stored as:

```
| 1 2 3 | 4 5 6 | 8 7 8 | 9 1 9 | 0 0 0 | 1 1 1 | 2 2 3 | 4 4 5 |
```

#source 3d-array.c

- as with the 1-dimensional array, the most "significant" dimension of the array
  may be omitted **if statically initialized**, but nothing below, i.e. these
  are fine:

```
int a[][5] = { 0 };
int a[][3][6] = { 0 };
```

However these are not:

```
int a[5][6][] = { 0 };
int a[5][][8] = { 0 };
```

- the reason is that if you do not know how may "lines" are there, it's OK, but
  you always need to know the "length" of the "line" so that you can put them
  one by one.

- see above for `a[2][4][3]` and its memory layout.  We can easily add a new
  element of `a` which is a 2-dimensional array, but there is no way we can
  store the `a` array unless we know the exact dimensions of the 2-d subarray.

- as before, if you do not initialize the rest, it will be set as 0.  You can
  also use
#module array-intro.md designated initializers
  the same way as with one-dimensional arrays.

- `sizeof` works as expected.  So, the following prints a size of of an element
  of `a`, which is an `[3][6]` subarray of `int`s, so `72` is printed (3 * 6 *
  sizeof (int)) unless you are on something you borrowed from the [Computer
  History Museum](https://computerhistory.org/).  If you happen to be in Silicon
  Valley, it is worth going to Mountain View to visit this one.

```C
int a[][3][6];
printf("sizeof = %zu\n", sizeof (array[0]));
```

:wrench: Define an array `[4][2]`, statically initialize it, and write a
function that accepts such an array and prints the first element from each `[2]`
subarray.

#source 2d-array.c

:wrench: write a program that takes a 2-D array of integers and constructs a 1-D
array of maximum values in each sub-array, then prints out the new array to the
standard output.  For the maximum value in a sub-array, write a function.

#source 2d-array-max.c

## VLA, multi-dimensional arrays, and function arguments

You can use variable-length arrays in function arguments themselves, like this:

```
int
myfn(int width, int a[][width])
{
	...
}
```
