# getchar()

- getchar() function reads one character from the process standard input and
  returns its value as an integer.
	- when it reaches end of input (for example, by pressing `Ctrl-D` in the
	  terminal), it returns `EOF`
	- `EOF` is a define, usually set as -1.  That is why getchar() returns
	  an `int` instead of a `char` as it needs an extra value for `EOF`.
	- getchar() needs `#include <stdio.h>`
	- you can verify that [`EOF` is part of `<stdio>`]
	(https://pubs.opengroup.org/onlinepubs/9699919799/)

### :wrench: Task: write code that will read characters from a terminal and prints them out.

It should work like this:
```
	$ cat /etc/passwd | ./a.out > passwd
	$ diff passwd /etc/passwd
	$ echo $?
	0
```
- remember, we said above that an assignment is just an expression, so it has a
  value.  So, you can do this:
```C
	if ((c = getchar()) == EOF)
		return (0);
```
  instead of:
```C
	c = getchar();
	if (c == EOF)
		return (0);
```

However, do NOT abuse it as you may create a hard to read code.  Note the
parentheses around the assignment.  The "=" operator has lower priority than the
"==" operator.  If the parens are not used, the following would happen:

`if (c = getchar() == EOF)` would be evaluated as:

`if (c = (getchar() == EOF))`, meaning that "c" would be either 0 or 1
		based on whether we read a character or the terminal input is
		closed.

We will learn more about operator priority later in the semester.

Solution: [getchar.c](/src/getchar.c)
