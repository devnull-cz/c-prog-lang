# Pointers

Motivation:
  - memory allocation / shared memory
  - protocol buffer parsing
  - pointer arithmetics

  - the value stored in "pointer" variable is the address of the memory
    storing given type
  - declared like this, e.g.

    `int *p; // pointer to an int`

    - note on style:

```C
      int * p;
      int *p;  // preferred in this lecture
```

  - good practice is to prefix pointers with the 'p' letter

  - a pointer is always associated with a type

  - to access the object the pointer points to, use a de-reference operator `*`:

```C
	printf("%d", *p);
```

  - the de-reference is also used to write value to the variable pointed:

```C
	*p = 5;
```

  - in a declaration, you may assign like this:

```C
	int i = 5;
	int *p = &i;
```

  - the `&` is an *address-of* operator and gets the address of the variable.

  - the pointer itself is obviously stored in memory too

```
     +---------------+
     |     addr2     |
     +---------------+
     ^                        +-------+
     |                        | value |
   addr1                      +-------+
                              ^
                              |
                            addr2
```

  - the size of the pointer depends on architecture and the way the program
    was compiled (see `-m32` / `-m64` command line switches of gcc)

    - `sizeof (p)` will return the amount of memory to store the address of the
      object the pointer points to
    - `sizeof (*p)` will return the amount needed to store the object the
      pointer points to

Task: write a program to print:
      - address of the pointer
      - the address where it points to
      - the value of the pointed to variable

Use the `%p` formatting for the first two.

:eyes: Code: [ptr-basics.c](/src/ptr-basics.c)

## NULL pointer

  - the real danger with pointers is that invalid access results in a crash (the
    program is terminated by kernel)

    - this is because `NULL` address is left unmapped on purpose, or a page that
      cannot be accessed maps to the address.  Note that C guarantees that zero
      is never a valid address for data.

  - can assign a number directly to a pointer (that should trigger a warning
    though.  We will get to casting and how to fix that later).

```C
	int *p = 0x1234;
```

  - special pointer value, `NULL`, is defined and it is called *a null pointer
    constant* [in the C spec](/modules/c99-standard.md).

Task: create NULL pointer and try to read from it / write to it

:eyes: Code: [null-ptr.c](/src/null-ptr.c)

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

	*p		// value of the pointed to variable
	*p + 1		// the value + 1
	*(p + 1)	// the value on the address + 1 (see below for what it
			// means)

   - note that the & reference operator is possible to use only on variables
     - thus this is invalid:

	p = &(i + 1);

  - store value to the address pointed to by the pointer:

	*p = 1;

## Changing pointers:

- pointers can be moved forward and backward

	p = p + 1;
	p++;
	p--;

## operator gotchas

- `*` has bigger precedence than `+` so:

	i = *p + 1;

is equal to

	i = (*p) + 1;

- postfix `++` has higher precedence than `*`:

	i = *p++;

is evaluated as `*(p++)` but it still does the following because `++` is used in
postfix mode, ie. the value of expression `p++` is `p`:

        i = *p; p++;

- the pointer is moved by the amount of underlying (domain) data type when using
  arithmetics

# Home assignment

Task: create pointer to int, print it, create new pointer that points to
      `p + 1`. See what is the difference between the 2 pointers.

Code: [ptr-diff.c](/src/ptr-diff.c)
