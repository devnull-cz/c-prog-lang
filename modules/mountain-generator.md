## Mountain scenery generator

:wrench: Write a simple moutain generator.  At every iteration you go either
straight (`-`), up (`/`), or down (`\`).  The program generates something like
the following:

```
$ a.out

               /                         /--
            / / \- /--                  /   \                       / /-
           / \    \   \              /--     \-                   /- \  \
          /            \            /          \             /-- /       \
      / /-              \-  /--   /-            \-          /   \         \
     / \                  \-   \ /                \-  /-- /-
    /                           \                   \-   \
 /--
-
```

**With all the variants below, try to make the code as simple as possible.** You
can do really cool stuff with quite little code.

You will need a two-dimensional array to fill, then print.  Use `memset()` to
initialize the array with spaces.  Check the man page for `memset`.  For the
first argument of `memset`, pass an array name.  Its dimension does not matter
in this case as long as you use its correct size in bytes.

For random numbers, use `rand()` and `%` for modulo.  To initialize the random
generator, use `sranddev()` if you have it, or `srand(time(NULL))`.  Check the
documentation if unsure (each function is supposed to have its manual page).

There is no language construct to initialize all elements of an array with a
specific non-zero value, that is why we need `memset`.  You can only zero it out
using an initializer `{ 0 }`, as we already know.

The algorithm goes from left to right, one character at a time. At each point it
decides whether the mountain will grow, descend or remain the same (hence the
random numbers).

Once you got a working program, refactor the code into small functions (one for
printing a character based on random number, one for printing the whole 2-D
array, etc.).  Optionally you can try to avoid global variables by passing the
array as parameter of a function.  In that case, you might try to use a VLA in
function arguments to see it works.  See [multi-dimensional
arrays](/modules/multi-dimensional-arrays.md) for more information.

:eyes: [mountain-generator.c](/src/mountain-generator.c)

### Variant: nicer mountain

You can make it more complicated and make the ascii art smoother.  For example,
you can define that after `/` you cannot go one character down with `\` (see
above what we mean) but you could do `/\`, etc.  You would need to keep a state
of the previous character.  You could generate something like this (use your
imagination):

```
            .
           / \
          /   \__
      /\_/       \__/|
     /               |
    /                \__/............................
  _/
```

### Variant: mountain range

The top-level function (`mountain()`) can be also called with the array (and its
dimensions) as input and you can try calling it multiple times to see if a
mountain range can be generated.

### Variant: add snow caps

Usually, there is snow on the peaks.

### Variant: ???

Come up with something else.

However, whatever you do, **the objective is to write simple code.** So, If you
have something cool, **send us the code, please!**
