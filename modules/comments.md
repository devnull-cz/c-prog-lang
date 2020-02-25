# Comments

- `/* one line comment */`

- multi line comment:
```
  /*
   * multi line comment.  Follow the C style.
   * multi line comment.  Follow the C style.
   */
```
- `// one line comment from C99+`

- preprocessor
	- defines
	- includes
	- conditional compilation
	- use parens for `#define` to prevent problems with macro expansion
		- `#define	X	(1 + 1)`
	- run the compiler with the -E flag to see preprocessor output

- Task: reimplement fahr-to-cent.c using defines instead of white numbers
	- solution: `fahr-to-cent_defines.c`


