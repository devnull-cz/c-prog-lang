# Preprocessor
  - defines
  - includes
  - conditional compilation
  - use parens for `#define` to prevent problems with macro expansion
  	- `#define	X	(1 + 1)`
  - run the compiler with the -E flag to see preprocessor output

To see the result of running preprocessor on your code, use `cpp` or
the `-E` option of the compiler.

- Task: reimplement fahr-to-cent.c using defines instead of white numbers
	- solution: `fahr-to-cent_defines.c`


