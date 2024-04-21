# Pointer to a pointer

We know that a pointer points to an object (unless its a null pointer or of type
`void`), e.g. an `int`.  However, the object may be another address, i.e.  a
pointer may point to another pointer.

```C
int i = 13;
int *pi = &i;
int **ppi = &pi;        // ppi is a pointer to a pointer to an int

// *pi is a pointer to an int, so another dereference is needed to get the value
printf("%d\n", **ppi);   // prints 13
```

You could write `*(*ppi)` but the associativity here is obvious and using
parentheses would be very unusual here.

## A pointer to a pointer to an array vs. a pointer to an array of pointers

Imagine this: let's assume we have an array of pointers to an `int`, as follows:

```C
int *p[10];     // note it is equivalent to "int *(p[10])"
```

Now, let's have a function that takes an array of `int` pointers and prints the
value pointed to by array's n-th element.  We know that when passing an array
as an argument, C converts it to a pointer.
So, `int *p[]` can be passed as an argument to an `int **p` parameter.

```C
void
foo(int **p, size_t idx)
{
        printf("%d\n", **(p + idx));
}
```

We can legally pass in any pointer to a pointer to an `int`.  Clearly, that
works fine in a situation when the object being passed in is indeed a pointer to
an array of `int` pointers.  Now what if someone passes in a pointer to a
pointer to an `int` array?

Note that in both situations, `ppa` and `ppb` **properly fit the declaration**
`int **p`.  **The difference is in semantics - is the actual array in the first
or the second indirection?** And that is a piece of information that must be
provided upfront by whoever wrote the function accepting such an argument.

```
    +-------+     +-------+     +-------+
 i  |   42  |   j |   7   |   k |   99  |
    +-------+     +-------+     +-------+
        ^           /      _______/
        |         /       /
    +-------+-------+-------+           +------+------+------+
 a  |   &i  |   &j  |   &k  |         b |  42  |   7  |  99  |
    +-------+-------+-------+           +------+------+------+
        ^                                   ^
        |                                   |
    +-------+                           +------+.......
ppa |   a   |                        pb |   b  |   ?  :
    +-------+                           +------+.......
                                           ^
                                           |
                                        +------+
                                    ppb |  pb  |
                                        +------+
```

- What is the difference in accessing the values?  I.e. what will `**(x + 1)`
  and `*(*x + 1)` do when `x` is `ppa` or `ppb`?
- Semantically, we could also pass in a pointer to an array of pointers to
  arrays of `int`s, which would have arrays on both levels in the above ASCII
  chart, and would still match the `int **p` declaration.
- The following source code closely follows the ASCII art schema above.  Please
  study the code and make sure you understand the output completely.  Which
  address from the program output corresponds to the value of `?` above?

#source ptr-ptr-array.c

Example output:

```
$ ./a.out
 &i = 0x7ffee68b1880 (42)
 &j = 0x7ffee68b187c (7)
 &k = 0x7ffee68b1878 (99)
  a = 0x7ffee68b1890
  b = 0x7ffee68b1884
 pb = 0x7ffee68b1884 [*pb = 42]
ppb = 0x7ffee68b1868 [*ppb = 0x7ffee68b1884]
first:
0x7ffee68b1880 = 42
0x7ffee68b1884 = 42
second:
0x7ffee68b187c -> 7 (in hex 0x7)
0x7ffee68b1890 -> -427091840 (in hex 0xe68b1880)
```

The situation above is taken from a real-life problem.  Quoting from
https://unixpapa.com/incnote/pam.html:

> When the conversation function is called, it is passed an array of prompts.
> This is always passed in as struct pam\_message `**mesg`. However, the
> interpretation varies. In Linux-PAM and OpenPAM this is a pointer to an array
> of pointers to pam\_message structures, whereas in Solaris it is a pointer to a
> pointer to an array of pam\_message structures. Frequently there is only one
> prompt being passed in, so it doesn't matter. Under either interpretation, the
> first structure is addressable as `**msg`. However, accessing subsequent
> elements is different. In Linux-PAM and OpenPAM, the second element is at
> `*(msg[2])`, while in Solaris it is at `(*msg)[2]`.

The situation when one prompt is passed only is similar to what happens when the
function `first`() in

#source ptr-ptr-array.c
is called for `ppa` and `ppb`: we see `42` in both cases (element `[0][0]`).
The problem manifests itself when we have and need to reference more than one
number (or more than one, as in the PAM situation above, `msg` structures).
