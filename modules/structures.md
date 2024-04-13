# Structures

## Basics

- Collection of one or more members, possibly of different types, grouped
  together under a single name.

- Is one of the two *aggregate types* (the other aggregate type is the *array*)

- Structures permit group of related members to be treated as a unit (precursor
  to a class in Object Oriented Programming).

- Structures can contain other structures.

- Structure is specified as:

```C
struct foo {
	... // members
};
```

e.g.

```C
struct foo {
	int a;
	char b;
};
```
- Any type can be a member of a structure that it not **incomplete** and not a
  function.  Incomplete means its size is unknown; more on that later.
	- That means a structure may not contain itself (before the structure
	  definition is finished with the terminating `}`, it is an incomplete
	  type as its size is not yet known)
		- There is a minor exception though, see C99 6.7.2.1, paragraph
		  2 and 16, and also a
#module flexible-array-member.md *flexible array member*.
	- However: a pointer to its own type is possible (remember, a pointer is
	  just a number referencing a piece of memory, and its size is known)
	- Unlike in C++, structure cannot contain functions. It may contain
	  pointers to functions, though.
- Structure does not need a name, #source struct-unnamed.c
	- However then its use is limited to a variable declaration
	- One can even have an "anonymous structure", however that is a C11
	  extension, #source struct-anon.c

- The `struct` declaration itself cannot contain initializers.  However, the
  structure can be initialized with a list of initializers in the same way as
  arrays.

So, you cannot do:

```C
struct foo {
	int a;
} = { 1 };
```

- When the structure has been defined, you can declare a variable of its type:

```C
struct foo f;
```

- Sometimes the `_s` or `_st` postfix is used to hint that a name is a structure

Note: the `struct` keyword has to be used for its definition and declaration:

`foo f;` is not valid.

- Can declare structure and objects of its type at the same time, and you can
  also initialize it at the same time:

```C
struct foo_s {
	...
} foo = { 0, ... };
```

- However, this is unusual because structures are normally saved to header
  files, and including such a header file would mean actual object definition(s)
  which is rarely desirable.

- For better code readability and also to be able to search for the members in
  (large) code base, members are often prefixed with a common string ending with
  an underscore to denote their structure membership, e.g.:

```C
/*
 * 'sin' is a shortcut for 'Sockaddr_IN', the Internet socket address
 */
struct sockaddr_in {
	short   sin_family;
	u_short sin_port;
};
```

- When looking for variable names in a big source code repository (using
  `ctags`, `cstyle` or tools such as
  [OpenGrok](https://github.com/opengrok/opengrok/)), there would be large
  amount of generally named variables like `port`, `size`, etc in various source
  code files.  However, with the prefix, like `sin_port`, very often you find
  just one, the one you are looking for.

## Structure layout in memory

```C
struct X { int a; char b; int c; };
```

- The offset of the first member will be always 0.

- Other members will be padded to preserve self-alignment (i.e. a member is
  always aligned in memory to multiple of its own size).
	- The value of the padding bits is undefined by definition and you must
	  not rely on it.

- What will be the result of `sizeof (struct X)` above?
	- Why? (think about efficiency of accessing members that cross
	  a word in memory).

- What if `char d` is added at the end of the data structure?
	- Why is that? (think about arrays and memory access again).

- What if `char *d` is added at the end of the data structure?  (i.e. it will
  have 4 members).
	- Assume this is being compiled on 64-bit machine.
	- For efficiency the access to the pointer should be aligned to its
	  size.
	- If in doubt, draw a picture.

```
+-----------+----+--------+------------+
|     a     | b  |   pad  |      c     |
+-----------+----+--------+------------+
```

- Does the compiler reorder struct members?  No, C is designed to trust the
  programmer.

#source struct-X.c

Note: gcc/Clang has the `-fpack-struct` option that will condense the members at
the expense of speed when accessing them.  Use only when you know what you are
doing as it may not be safe on all architectures.

Link: http://www.catb.org/esr/structure-packing/

## Structure members

Members are accessed via 2 operators: `.` and `->`

- Infix operators, left-to-right associativity, both are in the group of
  operators with the highest precedence (priority)
- `->` is used if the variable is a pointer, `.` otherwise

- E.g.:

```C
struct foo_s {
	int a;
	char b;
} foo;

foo.a = 42;
foo.b = 'C';
```

The `.` and `->` operators have higher precedence than `*` and `&`, so: `&foo.b`
gets the address of the member `b`.

Structure assignment is done byte by byte (shallow copy - does not follow
pointers):

```C
struct foo_s one, two;

one = two;
```

- Handy for members that are pointers.
- On the other hand for large structures (say hundreds of bytes) this can be
  quite an expensive operation.

Pointers to structures are often used:

```C
struct foo_s *foo;

foo->a = 42;
foo->b = 'C';
```

#source struct-reference.c

:wrench: Write the above assignments to the members `a` and `b` using a
de-reference operator on `foo`.

#solution struct-access.c

:wrench: now if `a` was a pointer to integer, how would the code change?

#solution struct-access-ptr.c

## Structure initialization

Can initialize a structure in its definition using the initiator list of values.

You must either follow the ordering of members:

```C
struct foo_s {
	int a;
	char b;
	char *s;
};

struct foo_s foo = { 1, 'C', "hello world" };
```

#source struct-init.c

or use *designated initializers* from C99:

```C
struct foo_s foo = {
	.b = 'C',
	.a = 1,
};
```

The ordering in the struct declaration does not have to be preserved (but you
really should follow it though).

Omitted field members are implicitly initialized the same as objects that have
static storage duration (ie. will be initialized to 0).

#source struct-designated-init.c

## Operations on structures

You can only:

- Copy a structure.
- Assign to it as a unit.
- Taking its address with `&`.
- Access its members.

So, structures cannot be:

- Compared (for that one has to implement a comparator function).
- Incremented (obviously).

## :wrench: Animals as structures

Define array of structures of this type:

```C
struct animal {
	char name[NAME_MAX];	// max filename length should be sufficient
				// even for these long Latin names
	size_t legs;		// can have many legs
};
```

And initialize it with some samples (can define the array in `animals.h`) and
implement a function:

```C
size_t count_minlegs(struct animal *, size_t len, size_t min);
```

That will return number of animals in the array (of `len` items) that have at
least `min` legs.

Notice that the function returns `size_t`. This way it is ready for future
expansion. If it returned `unsigned int` and 32-bits was not found enough later
on, the prototype would have to be changed which would cause problems for the
consumers of this API.

The function will be implemented in a separate file.  (Do not forget to create a
header file(s).)

In the `main()` program (first program argument will specify the `min` parameter
for the function) pass an array of structures to the function and report the
result.

Note: you will need:

- `limits.h` for the `NAME_MAX` definition
- `stddef.h` for `size_t` (as per C99, §7.17)

Code:
- #solution struct-animals.c
- #solution animal\_minlegs.c
- #solution animal.h
- #solution animals.h

Note: for compilation it is only necessary to compile the `*.c` files and then
link them together.

It can be done e.g. like this:

```
cc struct-animals.c animal_minlegs.c
```

The compiler will do the compilation of the individual object files and then
call the linker to contruct the binary (named `a.out`).

Or as follows which is closer to what would be done using a Makefile:

```
cc -c struct-animals.c animal_minlegs.c
cc -o animals struct-animals.o animal_minlegs.o
```

Technically, `animals.h` contains code, however, given it is included in a `.c`
file it is not necessary to compile it individually.

:wrench: Use the code from previous task and implement (in separate `.c` file)

```C
static size_t getlegs(struct animal *);
```

That will return number of legs for a given animal.
