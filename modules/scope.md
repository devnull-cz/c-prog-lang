# Scope

- Every identifier has its *scope*.

- The scope of an identifier is the part of the program within which the
  identifier name can be used.

- For example, we can declare a variable `int i` in the `main` function, and as
  well as in another function.  Those two variables reference different
  [objects](/modules/object.md).

- For now, we only care about two types of scope - a file, and a block.

- When declaring an identifier inside a block or within the list of parameter
  declarations in a function definition, the identifier has *block scope*.
  Its scope is from the identifier declaration to the end of the block.

- When declaring an identifier  outside of any block or list of parameters, the
  identifier has *file scope*.

- Note that a block is used in multiple constructs in C, e.g. `while`, `for`,
  etc.

- Within the inner block, an identifier of the same name declared in the
  outer block is hidden (and not visible).  See:

	- #source shadow.c
	- #source shadow-block.c
