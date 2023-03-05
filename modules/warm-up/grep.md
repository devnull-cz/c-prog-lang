## A trivial grep

:wrench: Write code to implement `grep *word*`

```
$ cat /etc/passwd | ./a.out root
root:x:0:0::/root:/bin/bash

```

Assume a reasonable maximum line width, e.g. 1024 bytes including the newline.
Print an error and exit with 1 (i.e. `return (1)` from `main`) when hitting a
line that crosses that limit.  Test that it works as expected!

Note that it is generally better to fail rather then silently choose what to do
on situations like that.  For example, just ignoring the rest of the line after
the 1024 byte limit which might be very confusing for users.

Solution: TBD.  You can send us your solution so that we use it here.  Do it as
simple as possible.
