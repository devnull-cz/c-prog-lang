# Program arguments

```C
int main(int argc, char *argv[]);
```

  - `argv` is declared as an array of pointers
    - i.e. `argv[i]` is a pointer to char
  - the arguments of `main()` can have arbitrary names however please stick
    to the convention to avoid confusion of those who might be reading your
    program

  - `argc` is a number of command line arguments, including the command name
    itself (in `argv[0]`).

  - `argv[i]` are arguments as strings.  Note, they are **strings** even if you put
    numbers there on the command line.

  - `argv[argc]` is NULL by definition.

Note: remember (see
#module arrays-as-function-arguments.md notes about array passed to function
) that in a function argument, an array is
      always treated as a pointer so the above effectively becomes:
```C
        int main(int argc, char **argv);
```
  i.e. in this context, char `*argv[]` and char `**argv` are the same.

  The declaration merely hints at the memory layout.

Also, you already know that you can use an array notation with characters as
well, so you could use `argv[i][j]` to print individual characters.  Just make
sure that it's not out of range.

Code: #source argv-as-2d-array.c


- the memory for `argc`, `argv` is allocated before `main()` is called
  - the standard (C99) leaves unspecified where argc/argv are stored

    > section 5.1.2.2.1: the strings pointed to by the argv array shall be
    modifiable by the program, and retain their last-stored values between
    program startup and program termination.

- the `argv` is array of pointers to null-terminated strings and must be
  terminated by a `NULL` pointer. (quote from the execve(2) man page)

```
  argv
  +-----------+
  |           |---------->+--------------+
  +-----------+           |              |---->+---+---+---+---+----+
                          +--------------+     | p | r | o | g | \0 |
                          |              |-\   +---+---+---+---+----+
  argc                    +--------------+  \
  +----------+            |              |-  \->+---+---+---+----+
  |    3     |            +--------------+ \    | f | o | o | \0 |
  +----------+            |     NULL     |  \   +---+---+---+----+
                          +--------------+   \
                                              ->+---+---+---+----+
                                                | b | a | r | \0 |
						+---+---+---+----+
```

## :wrench: Task: print command line arguments

  - print all command line arguments using `argc`
  - print all command line arguments using just `argv`
  - print all command line arguments not starting with `-`
  - print all command line arguments using a recursive function (that accepts pointer to pointer to char)

Note: for all arguments print their address as well

Note: do not print the terminating `NULL` entry
  - some `printf()` implementations barf on NULL pointer when printing via the
    `%s` format string

:key: Code:
  - #source argv-while.c
  - #source argv-for.c
  - #source argv-nodash.c
  - #source print-argv-recursively.c

## :wrench: Task: get char distance in specific argument

write a program with usage `./a.out <a> <b> <string>` to
find a distance between the first occurence of character `<a>` and `<b>` in a
string `<string>`.  If either of the character is not found in the string, print
an error.
```
./a.out a x "ahello xworld"
7
```
Note: do not use `strchr()` or the like.

:key: Code: #source argv-char-dist.c

## usage: semi-formal specification of program arguments

  - usually used to print when invalid option or arguments are specified
  - can be handled via errx()
  - the usage usually contains program name followed by the argument schema
    - see e.g. the nc(1) man page
  - optional arguments are enclosed in square brackets, mandatory arguments
    are enclosed in `<>` or left without brackets

Task: write a program that takes 1 or 2 arguments, if run with any other count,
      print usage and exit.

:key: Code: #source usage.c

## :wrench: Task: print the n-th character of the r-rd argument (count from 0)

usage: `./a.out <r> <n> [args]`

do not count `argv[0..2]`.  If not enough arguments or the argument is not long
enough, print a helpful message.  Only use pointer arithmetics, do **not** use
square brackets (ie.  `argv[i][j]` is **not** allowed).
```
./a.out 2 3 hey hi world
l
```
Note: use `atoi()` to convert the first 2 arguments to integers

:key: Code: #source argv-nr.c

## :wrench: Task: what do these programs do when run with 2 arguments

Assume that the arguments are sufficiently long enough.

Skipping ahead: prefix `++` and dereference operator have the same precedence
so they are evaluated based on associativity which is right-to-left.

```C
	int
	main(int argc, char **argv)
	{
		printf("%s\n", ++*++argv);
	}

	int
	main(int argc, char **argv)
	{
		printf("%s\n", argv[1]);
		printf("%s\n", ++*++argv);
		printf("%s\n", argv[0]);
		printf("%s\n", ++*++argv);
		printf("%s\n", argv[0]);
	}

	int
	main(int argc, char **argv)
	{
		printf("%s\n", *++*++argv);
	}
```

Note: the last function might not compile with smarter compilers (such as LLVM)
that include format string checks.  What is expected to happen if it the last
piece of code does compile and is run with one argument?

Code:
  - #source plus-deref-plus-argv.c
  - #source plus-deref-plus-deref-argv.c
