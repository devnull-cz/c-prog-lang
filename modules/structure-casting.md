# Pointer to a structure and type casting

Pointers to structures are often used to achieve common interface for different
types that all need to be passed as arugments to a function.  Consider this:

```C
struct common { int type; };
struct A      { int type; char data[8]; };	// type == 1
struct B      { int type; char data[16]; };	// type == 2
```

We have a `common` structure with the only structure member present in all
structures, `type`.  A function can be then declared as follows:

```C
int func(struct common *c);
```

However, the function needs to process additional members for structures `A`,
`B`, etc.  So, internally it may cast the argument to the specific structure
based on their common structure member, `type`:

```C
if (c->type == 1) {
	struct A *ap = (struct A *)c;
	ap->data[7] = 'A';
} else if (c->type == 2) {
	struct B *bp = (struct B *)c;
	ap->data[15] = 'B';
}
```

And the `func` is used like this, i.e. the non-`common` argument is always
casted to the `common` structure so that the compiler knows we know what we are
doing:

```C
struct A a;

if (func((struct common *)&a) == -1) {
	...
```

This is possible since all the structures have the same member on the same
offset (that is offset 0).  However, note that you need to cast properly to
avoid warnings.  See the code below.

#source struct-common.c

A function may also allocate an `A` or `B` structure and return its address as a
pointer to the `common` struct.  This pointer then needs to be casted in the
caller according to its first member.

See `struct sockaddr`, `struct sockaddr_in` and `struct sockaddr_in6`
definitions as an example on how this is done in practice.
