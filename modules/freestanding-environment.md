# Freestanding Environment

A *freestanding environment* is one in which C program execution may take place
without any benefit of an operating system.  In such an environment, the name
and type of the function called at program startup are *implementation-defined*.

For example, GRUB would not need to call its startup function `main()`.

The other type of the environment, one we will use, is called a *hosted
environment*.

See [C99 standard](/modules/c99-standard.md), 5.1.2.1, for more information if
interested.

If interested, see [here](/modules/behavior-types.md) for the definition of
*implementation-defined* behavior above.
