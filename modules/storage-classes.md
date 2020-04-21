# Storage classes

- two classes - *automatic* and *static*
- declaration within a block creates an automatic object
- the storage class determines the lifetime of the storage associated with the
  identified object
- only one storage class specifier may be given in a declaration
- objects declared outside of any block is always of the static storage class
  (e.g. global variables).
- static objects retain their value upon reentry to functions and blocks.
- you can initialize a static object.  The initialization happens just once.

code: #source fn-static-object.c

This one also shows how to use `goto`.  More on that later.

code: #source block-static-object.c
