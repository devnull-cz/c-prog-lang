# Function pointers

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

(void)process_numbers(7, 13, myadd));
```

#source fn-ptr.c

:wrench: Take the binary tree implementation and convert the depth-first
traversal function to accept a second argument that is a callback.  Implement
two callback functions - one that prints the integer type nodes, another that
prints the string type nodes (each callback will check the type of the node).
The callback has a single argument - pointer to a node.

## :wrench: Sort `argv`

Use `qsort(3)` function to sort `argv` and print it sorted then.  Check the man
page, you will need to write a function that compares two elements of the array
you provide to the `qsort()` function.

First use `strcmp()` to sort the argument alphabetically, then use `atoi()` (or
a function that actually checks if a string represents a number) to sort them
numerically.

After that, come up with another way of sorting the arguments (e.g. according
to their length etc.) and write a function for it as well.

#solution argv-sort.c
(for alphabetical sorting only)
