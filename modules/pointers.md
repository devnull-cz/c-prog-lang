# Pointers

A *pointer* is a reference to an entity, e.g. to an object of type `int`.  By
itself it is an object whose value is the reference (= memory address) to the
entity.

Motivation:

- Memory allocation / shared memory.
- Protocol buffer parsing.
- Pointer arithmetics.
- The value stored in a pointer object is the memory address storing the given
  pointer type.
  - Declared as follows, for example:

```C
int *p; // pointer to an int
```

- Note on style:

```C
int * p;
int *p;  // preferred in this lecture
```

- A pointer is always associated with a type.

- To access a value of the object the pointer points to, use a *dereference*
  operator `*`:

```C
printf("%d", *p);
```

- The dereference is also used to write a value to the object the pointer points
  to:

```C
*p = 5;
```

- You may assign a value to a pointer being declared:

```C
int i = 5;
int *p = &i;	// assign an address of 'i'
```

- Good practice is to prefix pointers with the 'p' letter, e.g.:

```C
int val = 5;
int *pval = &val;
```

- The `&` above is an *address-of* operator and gets the address of the object
  (i.e. the memory address of where the value is stored).

- The pointer itself is obviously stored in memory too (it is just another
  object as already said).  With the declarations above, it looks as follows:

```
     pval
     +---------------+
     |     addr2     |
     +---------------+        val
     ^                        +-------+
     |                        | 5     |
   addr1                      +-------+
                              ^
                              |
                            addr2
```

- The size of the pointer depends on the architecture and the way the program
  was compiled (see `-m32` / `-m64` command line switches of gcc)

- `sizeof (p)` returns the amount of memory to store the address of the
  object the pointer points to.  E.g. on 64 bit architecture, the pointer size
  is usually 8 bytes.
- `sizeof (*p)` returns the amount needed to store the object the pointer
  points to.  If a pointer points to an `int`, then `sizeof (*p)` will be
  usually 4 bytes.

:wrench: Write a program to print:

   - Address of the pointer.
   - The address where it points to.
   - The value of the pointed to variable.

Use the `%p` formatting for the first two.

#solution ptr-basics.c

## Null pointer

- The real danger with pointers is that invalid memory access usually results in
  a crash where the program is terminated by the kernel.
- We can assign a number directly to a pointer even that should trigger a
  warning.  We will get to casting and how to fix that later.

```C
int *p = 0x1234;
```

- Zero pointer value cast to `void *` is called *a null pointer constant* and is
  also defined as a macro `NULL`
#module c99-standard.md in the C specification.
  If a null pointer constant is converted to a pointer type such a pointer is
  called a *null pointer* and it is guaranteed in C not to point to any object
  or a function.  In other words, dereferencing a null pointer is guaranteed to
  terminate the program.
  - We will talk about `void` later but it is **a type that has no
    values**.  A pointer to such a type can never be dereferenced (as that
    would give us a value of the type but we just defined such a value
    does not exist).
  - This is because zero address is left unmapped on purpose, or a page
    that cannot be accessed maps to the address.
  - The C specification says that the macro `NULL` must be defined in
    `<stddef.h>`

```
$ cat main.c
int
main(void)
{
        void *p = 0;

        printf("%p\n", *p);
}

$ cc main.c
main.c: In function ‘main’:
main.c:8:24: warning: dereferencing ‘void *’ pointer
    8 |         printf("%p\n", *p);
      |                        ^~
main.c:8:24: error: invalid use of void expression
```

:wrench: Create a null pointer (i.e. assign `0` to a pointer) to a non-void type
(say an `int`) and try to read from and/or write to it, i.e. dereference such a
pointer.

#solution null-ptr.c

## Basic operations

- Note the difference:

```C
int i;
int *p = &i;
```

vs.

```C
int i;
int *p;

// set value of the pointer (i.e. the address where it points to).
p = &i;
```

- Operator precedence gotcha:

```C
*p		// value of the pointed to variable
*p + 1		// the value + 1
*(p + 1)	// the value on the address + 1 (see below for what it means)
```

- Pointers of the same type can be assigned to one another.

```C
int *p = 13;	// probably will trigger a warning
int *p2 = p;
```

- Note that the `&` address-of operator is possible to use only on objects that
  may be assigned values to.  The following is invalid then:

```C
p = &(i + 1);	// we cannot assign to (i + 1) like this: "(i + 1) = 1;"
```

#source ptr-lvalue.c

- Store value to the address pointed to by a pointer:

```C
*p = 1;
```

## Changing pointers:

Pointers can be moved forward and backward:

```C
p = p + 1;
p++;
p--;
```

**The pointer is moved by the amount of underlying data type when using
arithmetics.**

:wrench: Create a pointer to an `int`, print its value, create a new pointer
that points to `p + 1`. See what is the difference between the 2 pointers.  To
print a pointer value, use the `%p` conversion specifier.

#solution ptr-diff.c

## Operator gotchas

- The `*` dereference operator has higher precedence than `+`:

```C
i = *p + 1;
```

is equal to:

```C
i = (*p) + 1;
```

- Postfix `++` has higher precedence than `*`:

```C
i = *p++;
```

is evaluated as `*(p++)` but it still does the following because `++` is used in
postfix mode, ie. the value of expression `p++` is `p`:

```C
i = *p; p++;
```
