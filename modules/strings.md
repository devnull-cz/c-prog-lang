# Strings

- "xxx" is called a *string literal* or a *string constant*

- in memory it is a consecutive piece of memory: `'x' 'x' 'x' '\0'`

- `'\0'` terminates the string.  That's the C convention.

- `'\0'` is called a `NUL` character.  It's just a 0 byte but the convention is
  to use `'\0'` if it represents a string element.  `'\0'` is just a special
  case of octal representation `'\0ooo'` where 'o' is an octal figure (0-7).

- aside from the `{ 'x', ... }` initializer, character array initialization may
  be done also with a string literal:

```C
	/* sizeof (a) is 6 as the terminating 0 is counted in */
	char a[] = "hello";
```

- if {} is used, you must add the terminating zero yourself unless you use the
  size of the array and the string was shorter (in which case the rest would be
  initialized to zero):

```C
	char s[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
```

  Anyway, you would probably never do it this way.  Just use `= "hello"`.

  code: array-fill.c

- string is printed via printf as `%s`

```C
	printf("%s\n", "hello, world");
```

- experiment with what `%5s` and `%.5s` do (use any reasonable number)

code: string-format.c

# warmup

task:

  - extend the program tr-d-chars.c from last time to translate character input
    e.g.

    tail /etc/passwd | tr 'abcdefgh' '123#'

  - use character arrays defined with string literals to represent the 2 strings
    - see the tr(1) man page on what needs to happen if the 1st string is longer
      than the 2nd
      - do not store the expanded 2nd string as literal in your program !

  code: tr.c

task (bonus): refactor the code into function
		- remember that arrays are passed into function as a pointer (to
		  be explained soon, not needed now) that can be used inside the
		  function with array subscript
