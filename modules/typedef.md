# The `typedef` keyword

- note that a `char`, signed and unsigned integer types, and the floating types
  are collectively called *basic types*.
- then you have *derived types* - an array type, a structure, a union, a
  function type, a pointer type.

With `typedef`, you create new data type **names** for **existing** types.  Note
that you **never** create new data **types** with `typedef`.  In other words,
with `typedef`, you create synonyms to existing types.

`typedef` is most commonly used for derived types but many type names provided
by the C standard itself are based on even basic types.  For example, `size_t`,
see its definition in `/usr/include/sys/types.h`.

You can also create new type names using type names you created before, see
below.

`typedef` is used as follows:

```C
typedef int myint;
typedef *char mycharptr;

mycharptr p = "my string";
```

`typedef` is great to create complex type names in small steps.  As we will
see next.

```C
typedef char **array[10];
array a;
```

#source derived-types.c

The convention is to add `_t` to a new type name.  For example:

```C
typedef struct mystruct_s {
	int a;
	char c;
} mystruct_t;
```

And you can use it like this:

```C
struct mystruct_s x;
mystruct_t y;
```

`x` and `y` are of the same type.

#source typedef.c

:wrench: take the binary tree implementation and use `typedef` for the node
structure itself and also fot the callback.
