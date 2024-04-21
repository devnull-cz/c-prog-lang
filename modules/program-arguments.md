# Program arguments

```C
int main(int argc, char *argv[]);
```

- The `argv` is declared as an array of pointers.
	- i.e. `argv[i]` is a pointer to `char`

- The arguments of `main()` can have arbitrary names however please stick to the
  convention to avoid confusion of those who might be reading your program.

- The `argc` is a number of command line arguments, including the command name
  itself (in `argv[0]`).

- `argv[i]` are arguments as strings.  They are **strings** even if you put
  numbers there on the command line.

- `argv[argc]` is a null pointer by definition.

Note: remember (see
#module arrays-as-function-arguments.md notes about array passed to function
) that in a function argument, an array is
      always treated as a pointer so the above effectively becomes:

```C
int main(int argc, char **argv);
```

I.e. in this context, char `*argv[]` and char `**argv` are the same thing and
there is not a preferred option.

The declaration merely hints at the memory layout.  That is how it was concieved
by the fathers of C, unfortunately it often causes confusion.

Also, you already know that you can use an array notation with strings as
well, so you could use `argv[i][j]` to print individual characters.  Just make
sure that it is not out of range.

#source argv-as-2d-array.c

- The memory for `argc`, `argv` is allocated before `main()` is called and the
  C99 standard leaves unspecified where `argc`/`argv` are stored.

	> section 5.1.2.2.1: the strings pointed to by the argv array shall be
	modifiable by the program, and retain their last-stored values between
	program startup and program termination.

- A quote from the execve(2) man page on Unix systems:

>The `argv` is an array of pointers to null-terminated strings and must be
terminated by a null pointer.

If unsure, draw a diagram.  The memory addresses are just examples:

```
  argv
  +-----------+
  | 0xFF00    |---------->+--------------+
  +-----------+    0xFF00 |   0xBB0000   |------------>+---+---+---+---+----+
                          +--------------+   0xBB0000  | p | r | o | g | \0 |
                   0xFF08 |   0xFFAA00   |-\           +---+---+---+---+----+
  argc                    +--------------+  \
  +----------+     0xFF10 |   0xCCFF00   |-  \----------->+---+---+---+----+
  |    3     |            +--------------+ \    0xFFAA00  | f | o | o | \0 |
  +----------+            |     NULL     |  \             +---+---+---+----+
                          +--------------+   \
                                              ->+---+---+---+----+
                                      0xCCFF00  | b | a | r | \0 |
						+---+---+---+----+
```

## :wrench: Task: print command line arguments

- Print all command line arguments using `argc`
- Print all command line arguments using just `argv`
- Print all command line arguments not starting with `-`
- Print all command line arguments using a recursive function (that accepts
  pointer to pointer to char).

Note: for all arguments print their address as well.

Note: do not print the terminating null pointer entry.

Some `printf()` implementations barf on a null pointer when printing via the
`%s` format string.

Code:
- #solution argv-for.c
- #solution argv-do-while.c
- #solution argv-nodash.c
- #solution print-argv-recursively.c

Also see:
- #solution argv-while.c
- #solution argv-while-v2.c
- #solution argv-for-v2.c

## :wrench: Print command line arguments (part II.)

- Print all command line arguments without using square brackets.
- As above but do not use any variable aside from `argv`.

## :wrench: Get char distance in specific argument

Write a program with usage `./a.out <a> <b> <string>` to find a distance (number
of characters) between the first occurence of character `<a>` and `<b>` in a
string `<string>`.  If either of the character is not found in the string, print
an error.

```
./a.out a x "ahello xworld"
7
```

Note: do not use `strchr()` or the like.

#solution argv-char-dist.c

## Usage string: a semi-formal specification of program arguments

- Usually used to print when invalid option or arguments are specified
- Can be handled via `errx()`
- The usage usually contains program name followed by the argument schema
- See e.g. the `nc(1)` man page
- Optional arguments are enclosed in square brackets, mandatory arguments are
  enclosed in `<>` or left without brackets

:wrench: Write a program that takes 1 or 2 arguments.  If run with any other
count, print a meaningful usage and exit.

#solution usage.c

## :wrench: Print the n-th character of the r-th argument (count from 0)

Usage: `./a.out <r> <n> [args]`

Ignore `argv[0]`, `argv[1]`, and `argv[2]`.  If there are not at least `n` extra
arguments or the `n`-th argument is not long enough, print a helpful message.
Only use pointer arithmetics, do **not** use square brackets (ie.  `argv[i][j]`
is **not** allowed).

```
./a.out 2 3 hey hi world
l
```

Note: use `atoi()` to convert the first 2 arguments to integers

#solution argv-nr.c

## :wrench: What do these programs do when run with 2 arguments

Assume that the arguments are sufficiently long enough.

Skipping ahead: prefix `++` and dereference operator `*` have the same
precedence so they are evaluated based on associativity which is right-to-left.

```C
int
main(int argc, char **argv)
{
	printf("%s\n", argv[1]);
	printf("%s\n", ++*++argv);
	printf("%s\n", argv[0]);
	printf("%s\n", ++*++argv);
	printf("%s\n", argv[0]);
}
```

now with extra dereference:
```C
int
main(int argc, char **argv)
{
	printf("%s\n", *++*++argv);
}
```

Note: the last function might not compile with smarter compilers (such as LLVM)
that include format string checks.  What is expected to happen if the last piece
of code does compile and is run with one argument?

Code:
- #source plus-deref-plus-argv.c
- #source plus-deref-plus-deref-argv.c
