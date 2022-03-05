# Scope

- every identifier has its *scope*

- the scope of a name is the part of the program within which the name can be
  used.

- for example, we can declare a variable `int i` in the `main` function, and as
  well as in another function.  Those two variables reference different storage.

- for now, we only care about two types of scope - a file, and a block.

- when declaring an identifier inside a block or within the list of parameter
  declarations in a function definition, the identifier has *block scope*.
  Its scope is from the variable declaration to the end of the block.

- when declaring a variable outside of any block or list of parameters, the
  identifier has *file scope*.

- note that a block is used in multiple constructs in C, e.g. `while`, `for`,
  etc.

- within the inner block, an identifier of the same name declared in the
  outer block is hidden (and not visible) within the inner block.  See:

  - #source shadow.c
  - #source shadow-block.c
