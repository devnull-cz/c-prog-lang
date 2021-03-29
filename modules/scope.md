# Scope

- every identifier has its *scope*

- the scope of a name is the part of the program within which the name can be
  used.

- for example, we can declare a variable `int i` in the `main` function, and as
  well as in another function.  Those two variables reference different storage.

- for now, we only care about two types of scope - a file, and a block.

- when declaring a variable within the outer block of the function, its scope is
  from the variable declaration to the end of the function block.

- note that a block is used in multiple constructs in C, e.g. `while`, `for`,
  etc.

- #source shadow.c
#source shadow-block.c
