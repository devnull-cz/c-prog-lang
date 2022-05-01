# Function pointers.

A function name is a pointer to the function.  You can pass it as an argument.

```C
int
myadd(int a, int b)
{
	return (a + b);
}

int
process_numbers(int a, int b, int (*f)(int, int))
{
	return ((*f)(a, b));
}
```

#source fn-ptr.c

## :wrench: argv sorting

Use `qsort(3)` function to sort `argv`, and print it sorted then.  Check the man
page, you will need to write a function that can compare two elements of the
array you provide to the `qsort()` function.

First use `strcmp()` to sort the argument alphabetically, then use `atoi()`
(or a function that actually checks if a string represents a number)
to sort them numerically.

After that, come up with another way of sorting the arguments (e.g. according
to their length etc.) and write a function for it as well.

#solution argv-sort.c
(for alphabetical sorting only)
