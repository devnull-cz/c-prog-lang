# Strings and String Constants

We already know what a
#module string.md string
is.  It is an array of non-null characters terminated by a null byte.

- `"xxx"` is called a *string literal* or a *string constant*

	- do not confuse it with a *character constant*, e.g. `'A'`, as it uses
	  single quotes.  In contrast to Python, for example, single and double
	  quotes are two different things in C.

- **a string constant internally initializes an array of characters, with a null
  character appended.**

- we already know that a *string* is a contiguous sequence of characters
  terminated by and including the first null character

	- so, a string literal may include multiple null characters, thus
	  defining multiple strings.  In other words, a *string literal* and a
	  *string* are two different things.

```C
$ cat main.c
#include <stdio.h>

int
main(void)
{
	printf("%s\n", "hello\0world.");
}
$ cc main.c
$ ./a.out
hello
```

- a string constant may be used to initialize a char array and usually that is
  how the string initialization is used (in contrast to `{ 'a', 'b', ... }`)

```C
int
main(void)
{
	char s[] = "hello, world.";

	printf("%s\n", s);
}
```

```
$ gcc -Wall -Wextra main.c
$ ./a.out
hello, world.
```

- `'\0'` is just a special case of octal representation `'\0ooo'` where 'o' is
  an octal figure (0-7).

- remember that if `{}` is used for the initialization, **you must add the
  terminating zero yourself** unless you use the size of the array and the
  string was shorter (in which case the rest would be initialized to zero as
  usual):

```C
char s[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
```

- so, the following is still a propertly terminated string but do not use it
  like that

```C
char s[10] = { 'h', 'e', 'l', 'l', 'o' };
```

Anyway, you would probably never do it this way.  Just use `= "hello"`.

#source array-fill.c
#source array-fill2.c

- string is printed via `printf()` as `%s`

```C
printf("%s\n", "hello, world");
```

- experiment with what `%5s` and `%.5s` do (use any reasonable number)

#source string-format.c
