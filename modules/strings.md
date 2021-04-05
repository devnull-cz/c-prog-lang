# Strings and String Literals

- `"xxx"` is called a *string literal* or a *string constant*

- stored in a consecutive piece of memory: `'x' 'x' 'x' '\0'`

- `'\0'` terminates the string literal.  That's the C convention.

- a string literal internally initializes an array of characters from the
  string, with a `NUL` character appended.

- a *string* is a contiguous sequence of characters terminated by and including
  the first `NUL` character
  - so, a string literal may include multiple `NUL` characters, thus defining
    multiple strings.  In other words, a *string literal* and a *string* are two
    different things.

```C
int
main(void)
{
	char s[] = "hello, world\0, I arrived.";

	printf("%s\n", s);
}
```

```
$ gcc -Wall -Wextra main.c
$ ./a.out
hello, world
```

- `'\0'` is called a `NUL` character.  It's just a zero value byte but the
  convention is to use `'\0'` if it represents a string element.  `'\0'` is just
  a special case of octal representation `'\0ooo'` where 'o' is an octal figure
  (0-7).

- aside from the `{ 'x', ... }` initializer, character array initialization may
  be done also with a string literal:

```C
/* sizeof (a) is 6 as the terminating 0 is counted in */
char a[] = "hello";
```

- if `{}` is used for the initialization, you must add the terminating zero
  yourself unless you use the size of the array and the string was shorter (in
  which case the rest would be initialized to zero as usual):

```C
char s[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
```

Anyway, you would probably never do it this way.  Just use `= "hello"`.

#source array-fill.c

- string is printed via `printf()` as `%s`

```C
printf("%s\n", "hello, world");
```

- experiment with what `%5s` and `%.5s` do (use any reasonable number)

#source string-format.c
