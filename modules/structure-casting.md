# Pointer to a structure and type casting

- pointers to structures are often used to achieve common interface for
  different types

  - e.g.

```C
struct Common { int type; };
struct A      { int type; char data[8]; };	// type == 1
struct B      { int type; char data[16]; };	// type == 2
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

This is possible since all the structures have the same member on the same
offset (that is offset 0).

code: #source struct-common.c

Or, more commonly, a function will allocate a `A` or `B` structure and return
its address as a pointer to the `Common` struct.  This pointer then needs to be
casted according to its first member.

See `struct sockaddr`, `struct sockaddr_in` and `struct sockaddr_in6`
definitions for example on how this is done in practice.
