# Pointer to a pointer

We know that a pointer points to an object (unless its a `NULL` pointer or of
type `void`), eg. an `int`.  However, the object may be another address, i.e.
a pointer may point to another pointer.

```C
int i = 13;
int *pi = &i;
int **ppi = &pi;        // ppi is a pointer to a pointer to an int

// *pi is a pointer to an int, so another dereference is needed to get the value
printf("%d\n", **pi);   // prints 13
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
`int **p`.

           +-------+     +-------+     +-------+
         i |   42  |   j |   7   |   k |   99  |
           +-------+     +-------+     +-------+
               ^           /      _______/
               |         /       /
           +-------+-------+-------+           +------+------+------+
         a |   &i  |   &j  |   &k  |         b |  42  |   7  |  99  |
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

What is the difference in accessing the values?  I.e. what will `**(x + 1)` and
`*(*x + 1)` do when `x` is `ppa` or `ppb`?

#source ptr-ptr-array.c

This is from a real-life problem, quoting from https://unixpapa.com/incnote/pam.html:

> When the conversation function is called, it is passed an array of prompts.
> This is always passed in as struct pam\_message `**mesg`. However, the
> interpretation varies. In Linux-PAM and OpenPAM this is a pointer to an array
> of pointers to pam_message structures, whereas in Solaris it is a pointer to a
> pointer to an array of pam_message structures. Frequently there is only one
> prompt being passed in, so it doesn't matter. Under either interpretation, the
> first structure is addressable as `**msg`. However, accessing subsequent
> elements is different. In Linux-PAM and OpenPAM, the second element is at
> `*(msg[2])`, while in Solaris it is at `(*msg)[2]`.
