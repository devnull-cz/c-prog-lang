# Strings

An array of non-zero bytes (`char`s) terminated by a zero byte is called a
*string*.

```C
char foo[] = { 'b', 'a', 'r', 0 };
```

The crucial fact is that a string is always terminated by a *null* (zero) byte,
sometimes also called *NUL*.  That is how C knows where a string ends.  There is
no metadata involved with the string, e.g. a length.  To figure out the length
of a string, the string must be sequentially searched for the first null byte.

The string length is the number of bytes preceding the null character.

It also means the size of such an character array is **one byte more than the
number of characters in the string**.  It is because of the terminating zero
(`\0`) that the compiler adds to terminate the string. 

```C
char foo[] = { 'b', 'a', 'r', '\0' };

printf("%zu\n", sizeof (foo));		// prints 4
```

Using `'\0'` suggests it is a terminating null character but it is just a zero
byte.  So, you could use `0`, as follows, but it is not generally used:

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
