# Strings

A contiguous sequence of non-zero bytes (`char`s) terminated by a zero byte is
called a *string* (C99 7.1.1).

```C
char foo[] = { 'b', 'a', 'r', 0 };
```

Note that a string does not have to be declared as an array as shown above, it
may be just a piece of memory that meets the definition of a string above.

The crucial fact is that a string is always terminated by a *null* (zero) byte,
sometimes also called *NUL*.  That is how C knows where the string ends.  There
is no metadata involved with a string, e.g. its length.  To figure out the
length of a string, the string must be sequentially searched for the first NUL.

The string length is the number of bytes preceding the null character.

It also means the size of the array `foo` defined above is **one byte more than
the number of non-zero characters in the string**.  It is because of the
terminating zero (`\0`).  The NUL, by the C specification, belongs to the string
though.

```C
char foo[] = { 'b', 'a', 'r', '\0' };

printf("%zu\n", sizeof (foo));		// prints 4
```

Using `'\0'` suggests it is a terminating null character but it is still just a
zero byte.  So, you could use `0`, as follows, but it is not generally used:

```C
char foo[] = { 'b', 'a', 'r', 0 };
```

- To print a string via `printf`(), you use the `%s` conversion specifier:

```C
char foo[] = { 'b', 'a', 'r', 0 };

printf("%s\n", foo);	/* will print "bar" without the quotes */
```

:wrench: What happens if you forget to specify the terminating zero in the above
per-char initializator and try to print the string ?

#source array-char-nozero.c

Note that the following array of characters contains three strings:

```C
char foo[] = { 'a', '\0', 'b', 0, 'c', 0 };
```

And a character array does not need to be or contain a string at all:

```C
char not_a_string[] = { 'h', 'i' };
```

A special case of of initializing a character array that is to represent a
string is using double quotes.  The terminating zero will be the last character
of the array.

```C
char mys[] = "This is a string";

int i = 0;

/* Now print the string from the array one by one. */
while (mys[i] != '\0')
	printf("%c", mys[i++]);
printf("\n");

/* Normally, you would of course do the following. */
printf("%s\n", mys);
```

#source init-array-from-string.c

Note that the above really creates a local variable on the stack with its memory
initialized from the string when the code is executed.

```
$ cc init-array-from-string.c
$  strings a.out | grep bar
foobar
```
