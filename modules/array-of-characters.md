# Array of characters

An array of characters (`char`s) is called a *string* or a *string constant*.
Do not confuse it with a *character constant* as in `'A'`.

So, `"hello, world"` as string.

Technically, a string constant is an array of characters and may be used to
initialize a char array:

```C
  char foo[] = "bar";
```

A special thing is that a string is always terminated by a NUL (zero) byte.
That is how C know where a string ends.

That means the size of the array is one byte more than the number of characters
in the string.  It is because of the terminating zero (`\0`) that the compiler
adds to terminate the string.

So, you could use the initializer as introduced earlier:

```C
char foo[] = { 'b', 'a', 'r', '\0' };
```

However, that is no generally used, you would use `"bar"` to initialize such an
array.

Using `'\0'` suggests it is a terminating NUL character, and it is just a zero
byte.  So, you could just use `0`, like this, but it is not generally used:

```C
char foo[] = { 'b', 'a', 'r', 0 };
```

To print a string via `printf`(), you use the `%s` conversion specifier:

```C
printf("%s\n", foo);
```

:wrench: What happens if you forget to specify the terminating zero in the above
per-char init and try to print the string ?

:eyes: [array-char-nozero.c](/src/array-char-nozero.c)
