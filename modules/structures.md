# Structures

## Basics

- collection of one or more members, possibly of different types, grouped
  together under a single name

- structures permit group of related members to be treated as a unit (precursor
  to a class in Object Oriented Programming)

- structures can contain other structures

- structure is specified as:

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
- any type can be a member of a structure except the structure itself
  - however: a pointer to its own type is possible (remember, a pointer
    is just a number referencing a piece of memory)
  - unlike in C++, structure cannot contain functions. It may contain
    pointers to functions, though.
- structure does not have to have a name, #source struct-unnamed.c
  - however then its use is limited to variable declaration
  - one can even have an "anonymous structure", however that is a C11
    extension, #source struct-anon.c

- struct declaration cannot contain initializers.  However, the structure can be
  initialized with a list of initializers in the same way as arrays.

- define a variable:
```C
struct foo foo;
```

- usually the `_s` postfix is used to denote a structure name

 Note: the `struct` keyword has to be used for its definition and declaration:

`foo foo;` is not valid.

- can declare structure and its variables at the same time:

```C
struct foo_s {
	...
} foo;
```

- however usually this is not done because structures are normally saved to
  header files (and including such a header file would mean a variable
  definition which is usually not desirable)

- for better code readability, members are sometimes prefixed with a letter to
  denote their structure type, e.g.:

```C
// 'sin' is a shortcut for 'Sockaddr_IN', the Internet socket
// address
struct sockaddr_in {
	short   sin_family;
	u_short sin_port;
};
```

- another reason is when looking for variable names in a big source code
  repository (using `ctags` or `cstyle`), there would be large amount of
  generally named variables like `port`, `size`, etc in various source code
  files. However, with the prefix, like `sin_port`, very often you find just
  one, the one you are looking for.

## Struct layout in memory

```C
struct X { int a; char b; int c; };
```

- the offset of the first member will be always 0

- other members can be padded to preserve self-alignment (i.e. member is always
  aligned in memory to multiple of its own size)
	- the value of the padding bits is undefined

- what will be the result of `sizeof (struct X)` ?
	- why ? (think about efficiency of accessing members that cross
	  a word in memory)

- what if `char d` is added at the end of the data structure ?
	- why is that ? (think about arrays and memory access again)

- what if `char *d` is added at the end of the data structure ?  (i.e.  it will
  have 4 members)
	- assume this is being compiled on 64-bit machine
	- for efficiency the access to the pointer should be aligned to its size
	- if in doubt, draw a picture

```
+-----------+----+--------+------------+
|     a     | b  |   pad  |      c     |
+-----------+----+--------+------------+
```

- does the compiler reorder struct members ? no, C is designed to trust the
  programmer.

#source struct-X.c

note: gcc/Clang has the `-fpack-struct` option that will condense the members at
the expense of speed when accessing them.  Use only when you know what you are
doing as it may not be safe on all architectures.

link: http://www.catb.org/esr/structure-packing/

## Struct members

- members are accessed via 2 operators: `.` and `->`
	- infix, in the group of operators with the highest precedence
	- `->` is used if the variable is a pointer, `.` otherwise

- e.g.:

```C
struct foo_s {
	int a;
	char b;
} foo;

foo.a = 42;
foo.b = 'C';
```
- the `.` and `->` operators have higher precedence than `*` and `&`, so:

    `&foo.b` gets the address of the member `b`

- structure assignment

```C
struct foo_s one, two;

one = two;
```
- is done byte by byte (shallow copy - does not follow pointers)
	- handy for members that are pointers
	- on the other hand for large structures (say hundreds of bytes) this
	  can be quite an expensive operation

- pointers to structures:
```C
struct foo_s *foo;

foo->a = 42;
foo->b = 'C';
```

#source struct-reference.c

:wrench: Task: write the above assignments to the members `a` and `b` using a
de-reference operator on `foo`

#solution struct-access.c

:wrench: now if `a` was a pointer to integer, how would the code change ?

#solution struct-access-ptr.c

## Struct initialization

- can initialize in definition using the initiator list of **constant** values

```C
struct foo_s {
	int a;
	char b;
};

struct foo_s foo = { 1, 'C' };
```

#source struct-init.c

- or using *designated initializers* from C99:

```C
struct foo_s foo = {
	.b = 'C',
	.a = 1,
};
```

- the ordering in the struct declaration does not have to be preserved

- omitted field members are implicitly initialized the same as objects that have
  static storage duration (ie. will be initialized to 0).

#source struct-designated-init.c

## Operations on structures

You can only:

- copy a structure
- assign to it as a unit
- taking its address with &
- access its members

So, structures cannot be:

- compared
- incremented (obviously)

## :wrench: Task: animals as structures

define array of structures of this type:

```C
struct animal {
	char name[NAME_MAX];	// max filename length should be sufficient
				// even for these long Latin names
	size_t legs;		// can have many legs
};
```

and initialize it with some samples (can store the array in animals.h) and
implement a function:

```C
size_t count_minlegs(struct animal *, size_t len, size_t min);
```

that will return number of animals in the array (of `len` items) that have at
least `min` legs.

Notice that the function returns `size_t`. This way it is ready for future
expansion. If it returned unsigned int and 32-bits was not found enough later
on, the prototype would have to be changed which would cause problems for the
consumers of this API.

The function will be implemented in a separate file.  (Do not forget to create a
header file(s).)

In the `main()` program (first arg will specify the `min` parameter of the
function) pass the array of structs to the function and report the result.

Note: will need:

- `limits.h` for the `NAME_MAX` definition
- `stddef.h` for `size_t` (as per C99, §7.17)

code:
  - #solution struct-animals.c
  - #solution animal\_minlegs.c
  - #solution animal.h
  - #solution animals.h

Note: for compilation it is only necessary to compile the `*.c` files and then
link them together.

It can be done e.g. like this:

      cc struct-animals.c animal_minlegs.c

where the compiler will do the compilation of the individual object files and
then call the linker to contruct the binary (named `a.out`).

Or like this:

      cc -c struct-animals.c animal_minlegs.c
      cc -o animals struct-animals.o animal_minlegs.o

which is closer to what would be done using a Makefile.

Technically, `animals.h` contains code, however, given it is included in a `.c`
file it is not necessary to compile it individually.

:wrench: Task: use the code from previous task and implement (in separate `.c`
file)

      static size_t getlegs(struct animal *);

that will return number of legs for a given animal.

### animals: maximum number of legs

implement:

      struct animal *maxlegs(struct animal *, size_t len);

that will use the `getlegs()` function and will return an animal with highest
leg count. Return pointer to the structure (= array element) from the function.

The `main()` function (in separate file) will define an array of animals and
will call `maxlegs()`.  The name of the animal with maximum number of legs will
be printed to standard output.

Note: does the original structure change if the structure returned from the
function was modified within the function? How to fix this ?

code:
  - #solution animal\_maxlegs.c
  - #solution maxlegs.c
  - #solution animals.h
  - #solution animal.h

### :wrench: animal sorting

:wrench: (home) Task: sort the array by number of legs, print it out to standard
output.

:wrench: Task: sort the array by the animal name. Print it out to standard
output.  Use `strcmp()` to do the comparison of names.

:wrench: Task: add a function that will sort according to the number of legs

Make the comparison functions static.

Use the standard libc sort function qsort(3).  Check the manual page on how it's
used.  You will need to define a callback function that the qsort() function
will use to compare two array elements.

Make the program to accept an argument (0 or 1) and run the sorting function
based on that.

code:
  - #solution animal-sort.c
  - #solution animals.h
  - #solution animal.h

