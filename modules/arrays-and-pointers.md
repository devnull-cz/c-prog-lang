# Arrays and pointers

In C, there is a strong relationship between arrays and pointers.  Most of the
time, you can use array notation with pointers, and pointer notation with
arrays.

By definition, the value of a variable or an expression of type array is the
address of an element zero of the array.

```
int *pa;
int a[4] = { 1, 2, 3, 4 };

pa = &a[0];     // [] is of higher precedence than &
pa = a;         // this gets the same result as above

p[0] = 3;	// the array is now { 3, 2, 3, 4 }
*(a + 1) = 5;	// the array is now { 3, 5, 3, 4 }
```

heavy\_exclamation\_mark: As you can see, incrementing a pointer increments the
value **by the size of the object the pointer points to**.  Another example:

```
int a[] = { 0, 1, 2 };
int *p = a;

printf("%d\n", *(p + 2));       // will print 2
```

#source ptr-inc.c

:heavy\_exclamation\_mark: While you can work with arrays and pointers together,
**arrays are not pointers** and **pointers are not arrays**.  To work with a
pointer, the generated code must first get the value of the pointer variable,
then work with it.  With arrays, the generated code directly works with the
memory address the array starts at.  See below.

## Array variables are not modifiable

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

#source array-var-not-modifiable.c
