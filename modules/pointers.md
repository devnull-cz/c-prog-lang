# Pointers

Motivation:

- memory allocation / shared memory
- protocol buffer parsing
- pointer arithmetics

- the value stored in a pointer variable is the address of the memory storing
  the given pointer type
- declared like this, e.g.

```C
int *p; // pointer to an int
```

- note on style:

```C
int * p;
int *p;  // preferred in this lecture
```

- a pointer is always associated with a type

- to access the object the pointer points to, use a *dereference* operator `*`:

```C
printf("%d", *p);
```

- the dereference is also used to write a value to the variable pointed:

```C
*p = 5;
```

- in a declaration, you may assign like this:

```C
int i = 5;
int *p = &i;
```

- good practice is to prefix pointers with the 'p' letter, e.g.:

```C
int val;
int *pval = &val;
```

- the `&` is an *address-of* operator and gets the address of the variable (i.e.
  the memory address of where the value is stored)

- the pointer itself is obviously stored in memory too (it's just another
  variable).  With the declarations above, it looks as follows:

```
     p
     +---------------+
     |     addr2     |
     +---------------+        i
     ^                        +-------+
     |                        | 5     |
   addr1                      +-------+
                              ^
                              |
                            addr2
```

- the size of the pointer depends on the architecture and the way the program
  was compiled (see `-m32` / `-m64` command line switches of gcc)

- `sizeof (p)` will return the amount of memory to store the address of the
  object the pointer points to
- `sizeof (*p)` will return the amount needed to store the object the pointer
  points to

:wrench: write a program to print:

   - address of the pointer
   - the address where it points to
   - the value of the pointed to variable

Use the `%p` formatting for the first two.

#solution ptr-basics.c

## Null pointer

- the real danger with pointers is that invalid memory access results in a crash
  (the program is terminated by kernel)
- can assign a number directly to a pointer (that should trigger a warning
  though.  We will get to casting and how to fix that later).

```C
int *p = 0x1234;
```

- zero pointer value is called *a null pointer constant* and is defined as
  a macro `NULL`
#module c99-standard.md in the C specification.
  `NULL` is converted to a *null pointer* which is guaranteed in C not to point
  to any object or function.  In other words, dereferencing a null pointer is
  guaranteed to terminate the program.

	- this is because zero address is left unmapped on purpose, or a page
	  that cannot be accessed maps to the address.

	- the C specification says that the macro `NULL` must be defined in
	  `<stddef.h>

:wrench: create the null pointer and try to read from it / write to it

#solution null-ptr.c

## Basic operations

- notice the difference:

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

- operator precedence gotcha:
```C
*p		// value of the pointed to variable
*p + 1		// the value + 1
*(p + 1)	// the value on the address + 1 (see below for what it means)
```
- note that the & reference operator is possible to use only on variables
  - thus this is invalid:

```C
p = &(i + 1);
```

- store value to the address pointed to by the pointer:

```C
*p = 1;
```

## Changing pointers:

Pointers can be moved forward and backward

```C
p = p + 1;
p++;
p--;
```

**The pointer is moved by the amount of underlying data type when using
arithmetics.**

:wrench: create a pointer to an `int`, print it out, create a new pointer
that points to `p + 1`. See what is the difference between the 2 pointers.

#solution ptr-diff.c

## Operator gotchas

- `*` has bigger precedence than `+` so:

```C
i = *p + 1;
```

is equal to

```C
i = (*p) + 1;
```

- postfix `++` has higher precedence than `*`:

```C
i = *p++;
```

is evaluated as `*(p++)` but it still does this
```C
i = *p; p++;
```

  - because `++` is used in postfix mode, ie. the value of expression `p++` is `p`:
