# Opaque structures

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
