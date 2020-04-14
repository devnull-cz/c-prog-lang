## Opaque structures

It is possible to declare structure in a header file along with API that
consumes it:

```C
// foo.h
struct foo;
void doStuff(struct foo *f);
```

the file implementing `doStuff()` will contain:

```C
struct foo {
    int x;
    int y;
};

void
doStuff(struct foo *f)
{
	f->x = ...
	f->x = ...
}
```

Then any `.c` file that includes `foo.h` can work with the structure
(by passing it to `doStuff()`) however cannot access its members directly.
The structure is usable only via pointer. Thus, the library has to provide
a function to allocate a structure and return the pointer to it
(and possibly also to initialize it) and functions to get/set the data
inside the structure.

This is handy for libraries so they are free to change the layout of structures
without breaking the consumers.

code:
  - #source foo.h
  - #source foo.c
  - #source foo-user.c

## Pointer to a structure and type casting

- pointers to structures are often used to achieve common interface for
  different types

  - e.g.

```C
    struct Common { int type; };
    struct A      { int type; char data[8]; };	// type == 1
    struct B      { int type; char data[16]; }; // type == 2
```
  - then a function can be declared like so:
```C
    int func(struct Common *c);
```
  - internally it can do e.g.:
```C
    if (c->type == 1) {
    	struct A *ap = (struct A *)c;
	ap->data[7] = 'A';
    } else if (c->type == 2) {
    	struct B *bp = (struct B *)c;
	ap->data[15] = 'B';
    }
```
  - this is possible since all the structures have the same member
    on the same offset (that is offset 0)

code: #source struct-common.c

Or, more commonly, a function will allocate a `A` or `B` structure and return
its address as pointer to the `Common` struct. This pointer then needs to be
casted according to its first member.

See `struct sockaddr`, `struct sockaddr_in` and `struct sockaddr_in6`
definitions for example on how this is done in practice.

## :wrench: task: offsetof

write a macro (or start with a function with hardcoded values)
that will print the offset of the specified member of a given structure.

      offsetof(struct X, a)

hint: exploit the fact that pointer can be assigned an integer (0) + use pointer
arithmetics

note: `offsetof()` is standard macro available since ANSI C via stddef.h

:key: code: #source offsetof.c

## bit fields

- sometimes memory is scarce (imagine having to keep millions of big
  structures in memory) and there are members holding integer values that occupy
  just a couple of bytes
  - bit fields can be used to shrink the memory needed
```C
struct foo {
	unsigned int a : 3;
	unsigned int b : 1;
	unsigned int   : 4;
};
```
 - the number after the colon specifies the number of bits for given bit field
   - cannot exceed the size of the underlying data type (`unsigned int` in the
     above example)
 - cannot use `sizeof` on bitfield

 - this is good for implementing network protocol headers or HW registers,
   however the layout of bit fields in C structure is implementation dependent
   - if it needs to match a concrete layout, additional non-standard compiler
     features have to be used (`#pragma`'s etc.)
   - there is no `offsetof()` for bit fields

code: #source bitfield.c

- the integer values will behave as expected, e.g.
```C
  unsigned int a : 3;

  a = 7;
  a++; // will wraparound to 0 since this is unsigned
```

## :wrench: task: linked list

declare a structure that will form a simple linked list and will
hold an integer as a value. The program will be run with a single argument
specifying how many items the list will have.

Allocate a new structure and insert into the head (global variable).  Each new
item will have its value incremented by one.

Once the list is complete, print its value by traversing its items from head to
end.

:key: code: #source linked-list-free.c

## flexible array member

- since C99 (§6.7.2.1, item 16, page 103)
- it is an array without a dimension specified that is the last member of the
  structure
  - this is handy for structures with a fixed header and "padding" data of
    flexible length that is allocated dynamically
  - why not to use a pointer instead ? this is good when passing data over
    boundaries such as network, kernel/userland, etc. since no deep
    structure copy is required
    - just copy the structure as whole (it is just necessary to know how
      large it is) because it is all contiguous memory

- e.g.:
```C
  struct item {
      int value;
      // possible other members
      char payload[];
      // nothing can follow
  };
```

- `sizeof (struct item)` will give the size without the last member computed

```
	+-------------+-----------------------+
	| struct item |      payload ...      |
	+-------------+-----------------------+
```

- previously, this was hacked around using array with 0 members and GCC accepted
  this. Since C99 this can be done properly using this technique.
- the data is allocated like so:

```C
    struct item *p = malloc(sizeof (struct item) +
        payload_len * sizeof (p->payload[0]));
```

- with this approach the overall structure alignment might be lost
  - i.e. it is necessary to set the payload length according to the size
    of the structure if you want to maintain alignment

code: #source flexible-array-member.c
