# 2D array initialization

Static array initialization is just an extension of 1D array initialization.  It
is an array of arrays, so each element of the array (of arrays) is an array
initializer.  You initialize by rows.

```C
int a[MYSIZE][MYSIZE] = {
        {  0,  1,  2,  3 },     // a[0]
        {  4,  5,  6,  7 },     // a[1]
        {  8,  9, 10, 11 },     // a[2]
        { 12, 13, 14, 15 },     // a[3]
};
```

code: #source 2d-static-array-initialization.c

C stores the array in a single piece of memory, consequtively, row after row.
That means that all but the last dimension must be known.  So you could do:

```C
int a[][3] = {
        {  0,  1,  2 },
        {  4,  5,  6 },
        {  8 },         // a[2][1], a[2][2] implicitly initialized to 0
        { 12, 13, 14 },
}
```

However, you cannot do:

```C
int a[][] = {
        {  0,  1,  2 },
        {  4,  5,  6 },
        {  8,  9, 10 },
        { 12, 13, 14 }  // no comma here, that's OK, but it's
                        // recommended to use it to make it consistent
}
```

```
xxx.c:12:7: error: array has incomplete element type 'int []'
        int a[][] = {
             ^
```

The word *incomplete* here means the storage size of the array element (which is
an array itself) is unknown.

Note that in C99, you may or may not use a comma (`,`) after the last
initializer.  In C89, it was prohibited to use the comma after the last one.

Remember that we do not have to set all elements of the row when initializing an
array, the C compiler will zero out the rest.

```C
int a[10] = { 1, 2 }; // from a[2] to a[9], elements are 0
```

Neither you can do the following (same compiler error as above).  As the
compiler stores the array data in rows, if it does not know how long is the row,
it cannot proceed.

```C
int a[4][] = {
        {  0,  1,  2 },
        {  4,  5,  6 },
        {  8,  9, 10 },
        { 12, 13, 14 }
}
```

You already know that you can initialize a character array using a string
instead of `{ 'a', 'b', ... }`:

```C
char s[] = "hello, world";
```

Same way you can initialize an array of strings.  We already know from the
#module operator-precedence.md operator priority
that `[]` is of higher priority than `*`, so the following is an array of
pointers to `char`.


```C
char *s[] = {
        "hello",
        "hi",
        "good day",
        "what's up"
};
```

Note that if you wanted a pointer to an array of `char`s, it would be `char
(*s)[]`.  More on that later.

However, while string is technically an array of characters, it's technically an
array whose value is the address of its 1st element, i.e. the 1st character.
However, `{ 'a', 'b', ... }` is an initializer for a static array, it is not a
pointer.  So, the following will not compile:

```C
char *s[] = {
        { 'h', 'e', 'l', 'l', 'o', '\0' },
        { 'h', 'i', '\0' }
};
```

Same as the following is incorrect:

```C
char *s = { 'a', '\n' };
```

Also note that the following two lines mean something quite different:

```C
char a[] = "hello, world";
char *p = "hello, world";
```

In the first case, the string is only used to initialize a static array.  You
cannot assign anything to `a` after that but you can change the array's
elements.

In the second case, a static string is created and stored in the binary (i.e.
the program file), and `p` contains its address, i.e. the address of character
`'h'`.  One can change the `p` variable to point to something else but it is
undefined what happens when one tries to change the characters of the string
(which is internally an array of `char`s).  With `gcc`, all such strings are
read-only:

```C
$ cat main.c
#include <sys/types.h>

int
main(void)
{
        char *p = "hello, world";

        *p = 'H';
        return (0);
}
$ gcc main.c
$ ./a.out
Bus error: 10
```

Wikipedia:

> In computing, a bus error is a fault raised by hardware, notifying
> an operating system (OS) that a process is trying to access memory that the
> CPU cannot physically address: an invalid address for the address bus, hence
> the name.
