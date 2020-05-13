# Opaque structures (handles)

With the help of incomplete types, it is possible to declare a structure in a
header file along with API that consumes it without revealing what the structure
actually contains.  The reason to do that is not to allow a programmer to depend
(= use) on the structure members, thus allowing to change the structure innards
anytime.

```C
/* Forward declaration in foo.h */
struct foo;

void
do_stuff(struct foo *f);
```

The file implementing `do_stuff()` will contain:

```C
/* in foo_impl.h not provided to the consumers */
struct foo_impl {
    int x;
    int y;
};

/* library implementation code */
void
do_stuff(struct foo *f)
{
	struct foo_impl *fi = (struct foo_impl *)f;

	fi->x = ...
	fi->x = ...
}
```

Then any `.c` file that includes `foo.h` can work with the structure
(by passing it to `do_stuff()`) however cannot access its members directly.
The structure is usable only via a pointer. Thus, the library has to provide
a function to allocate a structure and return the pointer to it
(and possibly also to initialize it) and functions to get/set the data
inside the structure.

This is handy for libraries so they are free to change the layout of structures
without breaking the consumers.

The consumer of the library then `#include`s only `foo.h` but it does not have
access to `foo_impl.h`.

```C
#include <stdio.h>

#include "foo.h"

int
main(void)
{
	struct foo *h;

	h = getFoo();
	doStuff(h);
}
```

:eye:
  - #source foo.h
  - #source foo\_impl.h
  - #source foo.c
  - #source foo-consumer.c
