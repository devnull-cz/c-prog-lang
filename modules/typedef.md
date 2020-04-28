# The `typedef` keyword

- note that a `char`, signed and unsigned integer types, and the floating types
  are collectively called *basic types*.
- then you have *derived types* - an array type, a structure, a union, a
  function type, a pointer type.

With `typedef`, you create new data type **names** for **existing** types.  Note
that you **never** create new data **types** with `typedef`.  In other words,
with `typedef`, you create synonyms to existing types.

`typedef` is most commonly used for derived types but many C provided names by
the standard are based on basic types.  For example, `size_t`, see its
definition in `/usr/include/sys/types.h`.

`typedef` is used as follows:

```C
typedef int myint;
typedef *char mycharptr;

mycharptr *p = "my string";
```

`typedef` is also great to create complex type names in small steps.  As we will
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

:wrench: Task

Use `typedef` in the warm-up code for the item structure and use the new name
instead of `struct item ...`.
