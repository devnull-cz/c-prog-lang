# String length

We know that we can use `sizeof` to get a length of a character array including
the terminating `'\0'` character.  There is a more general way to get a string
length, function `strlen`().  Note that when we know what pointers are, the
existence of the fuction will make more sense.

The function is declared in `<string.h>` and returns a value of type `size_t`,
that is the same type as the operator `sizeof` uses.  So, remember to use the
`z` modifier to the `%u` conversion specifier:

```C
#include <string.h>

char s[] = "hello, world";

printf("Length of \"%s\": %zu\n", s, strlen(s));
```

Note that to include a literal `"` in a string, you just escape it.

## Checking empty string

`strlen()` can be used to check if string is empty, however if not, it will
incur performance penalty as it has to go through all the characters.

Thus, it is better to check just the first character - if it is `\0` then
the string is empty.

#source string-isempty.c
