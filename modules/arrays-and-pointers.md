# Arrays and pointers

In C, there is a strong relationship between arrays and pointers.

By definition, the value of a variable or an expression of type array is the
address of an element zero of the array.

```
pa = &a[0];     // [] is of higher precedence than &
pa = a;         // this gets the same result as above
```

heavy\_exclamation\_mark: Incrementing a pointer increments the value **by the
size of the object the pointer points to**.  Ie.

```
int a[] = { 0, 1, 2 };
int *p = a;

printf("%d\n", *(p + 2));       // will print 2
```

[ptr-inc.c](/src/ptr-inc.c)

## Arrays are not variables though

You cannot do the following:

```
int a[1];
int aa[1];
++a;            // error
a = aa;         // error
```

When assigning to an array element, the compiler generates code that assigns to
a piece of memory representing the element using an offset from the beginning
of the array.

```C
int a[1];

a[0] = 15;
```

The generated assembler code (e.g. `objdump -d` from LLVM) for the above assigns
15 directly to the piece of memory on the stack (started by the base pointer
`rbp`) that represents the first array element.  That also hints that one cannot
assign to an array variable in C as it would need a special semantics that would
not fit the way C works with arrays.

```
100000fa6:      c7 45 fc 0f 00 00 00    movl    $15, -4(%rbp)
```

[arrays-are-not-vars.c](/src/array-var-not-modifieable.c)
