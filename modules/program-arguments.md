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

Note: remember (see lecture 07 notes) that in a function argument, an array is
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
