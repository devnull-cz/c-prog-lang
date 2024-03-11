## A trivial fgrep

There are multiple variants of the grep(1) Unix utility. One of them is
`fgrep` aka `grep -F` that prints the lines received on standard input which
contain given fixed string (as opposed to a regular exception).
`fgrep` can match multiple strings.

:wrench: Write code to implement part of the `fgrep` functionality where the
program will match a single string which is hard-coded in the program
in the form of (boundless) array (`char needle[] = "foobar";`).
The program will use `getchar()` to read the characters from the standard input.

Sample program run (with the search string hard-coded as `bash`):
```
$ cat /etc/passwd | ./a.out
root:x:0:0:root:/root:/bin/bash
foo:x:1000:1000:Foo,,,:/home/foo:/bin/bash
backu:x:1001:1001:backup,,,:/home/backu:/bin/bash
perforce:x:133:141:Perforce Admin:/opt/perforce:/bin/bash
```
compared to the fgrep(1) utility:
```
$ fgrep bash /etc/passwd
root:x:0:0:root:/root:/bin/bash
foo:x:1000:1000:Foo,,,:/home/foo:/bin/bash
backu:x:1001:1001:backup,,,:/home/backu:/bin/bash
perforce:x:133:141:Perforce Admin:/opt/perforce:/bin/bash
```

Assume a reasonable maximum line width, e.g. 1024 bytes including the newline.
Print an error and exit with 1 (i.e. `return (1)` from `main`) when hitting a
line that crosses that limit.  Test that it works as expected!

The line limit is enforced to make the program simple, i.e. prevent using huge
amounts of memory and avoid memory reallocation.

Note that it is generally better to fail rather then silently choose what to do
on situations like that.  For example, just ignoring the rest of the line after
the 1024 byte limit which might be very confusing for users.

Write tests (as a home assignment), watch out for corner cases.

Solution: TBD. You can send us your solution so that we use it here.  Do it as
simple as possible.
