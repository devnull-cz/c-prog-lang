# Strings, arrays, and pointers

We already went through
#module string.md basics on strings
and
#module strings-and-string-constants.md string literals.

Given that a string constant is internally used to initialize an array of
`char`s, and an array name represents its first element memory address, the
value of a string is an address of its first character.

#source string-const-address.c

You can use an array notation with pointers.  So, if you **really** wanted, you
could do something like this:

```C
printf("%c\n", "hello, world"[1]);	// will print `e`
```

## Strings and pointers

Given that a string constant is a pointer to its first character, we can use it
like this:

```
char *p = "hello";

printf("%c\n", p[1]);   // will print 'e'
```

#source array-notation-with-ptr.c

:heavy\_exclamation\_mark: Pointer initialized with a string literal **may not**
be changed in the same way as array.  The internal array created and
initialized from the string literal is in read-only by the specification.
Writing to it is an undefined behavior.  Writing to it with `gcc` and `clang`
will crash the program.  However, for example, [Oracle Developer
Studio](https://www.oracle.com/application-development/technologies/developerstudio.html)
puts such arrays into read-write memory.  So, working code complied with that
compiler and modifying string literals will crash if compiled those other two.

#source string-literal-write.c

And as you can use a pointer notation with arrays (we already mentioned that the
array name is a synonym for the address of its first element), you can do this:

```
char a[] = "hello, world";

printf("%c\n", *(a + 1));       // will print 'e'
```

#source ptr-with-array-notation.c
