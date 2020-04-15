# Pointer to a pointer

We know that a pointer points to an object (unless its a `NULL` pointer or of
type `void`), eg. an `int`.  However, the object may be another address, i.e.
a pointer may point to another pointer.

```C
int i = 13;
int *pi = &i;
int **ppi = &pi;        // ppi is a pointer to a pointer to an int

// *pi is a pointer to an int, so another dereference is needed to get the value
printf("%d\n", **ppi);   // prints 13
```

## A pointer to a pointer to an array vs. a pointer to an array of pointers

Imagine this: let's assume we have an array of pointers to an integer, like
this:

```C
int *p[10];     // note it is equivalent to "int *(p[10])"
```

Now, let's have a function takes an array of `int` pointers and prints the
array's n-th element.  We know that when passing an array as an argument, C
converts it to a pointer.   So, `int *p[]` can be written as `int **p`.

```C
void
foo(int **p, size_t idx)
{
        printf("%d\n", **(p + idx));
}
```

Clearly, this works fine in a situation when `pp` is indeed a pointer to an
array of integer pointers (left).  Now what if someone passes a pointer to a
pointer to an integer array (right)?

Note that in both situations, `ppa` and `ppb` **properly fit the declaration**
`int **p`.  That is, both arrays in the chart below are 2-dimensional and both
have one of the dimensions set as `1`.  **The difference is which of the two
dimensions is `1`.**  And that is a piece of information that must be provided
upfront.

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
is called for `ppa` and `ppb` - we see `42` in both cases (element `[0][0]`).
The problem manifests itself when we have and need to reference more than one
number (or more than one, in the PAM situation above, `msg` structures).
