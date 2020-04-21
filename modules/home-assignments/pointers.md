## Work with arrays and pointers

- Define two integers `i`, `j` and initialize them with some arbitrary values.
- Define an array `a` of pointers to `int` that contains pointers to these two
  integers.
- Define an array `b` of `int`s that will contain the values of these two
  integers.
- Define a pointer `p`, and assign i-th element of array `a` to it.
- Define a pointer `q`, and assign an address of the i-th element of array `b`
  to it.
- Print the address of `p`, `q` and then deference them.

What you are expected to get when dereferencing the `p` and `q` pointers?

What is the distance between these 2 pointers?  Does it make sense to do that?
A difference between two pointers is a signed integer of type `ptrdiff_t`.  To
print it out via `printf`, use a `t` modifier.

```C
int a[2];
int *p = &a[1];
int *q = &a[0];

printf("%td\n", p - q);
```

Usage: `./a.out <i>`

What is a reasonable value of the 1st argument (`i`) of the program ?

#source ptr-to-array-of-ptrs.c
