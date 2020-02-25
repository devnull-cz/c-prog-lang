# Home assignment: digit occurrence

It's voluntary but writing code is the only way to learn a programming language.

If unsure about the behavior, compile our solution and run it.

- count occurence of each 0-9 digit.  Only use what we have learned so far.
  You end up with longer code than otherwise necessary but that is OK.

```
	$ cat /etc/passwd | ./a.out
	0: 27
	1: 37
	2: 152
	3: 38
	4: 39
	5: 43
	6: 34
	7: 35
	8: 29
	9: 31
```

Solution: [count-numbers.c](/src/count-numbers.c)

- convert small characters to upper chars in input.  Use the fact that a-z and
  A-Z are in two consequtive sections of the ASCII table.

	- use the else branch:
```
	if (a) {
		...
	} else {
		...
	{

	$ cat /etc/passwd  | ./a.out
	##
	# USER DATABASE
	#
	# NOTE THAT THIS FILE IS CONSULTED DIRECTLY ONLY WHEN THE SYSTEM IS RUNNING
	# IN SINGLE-USER MODE.  AT OTHER TIMES THIS INFORMATION IS PROVIDED BY
	# OPEN DIRECTORY.
	#
	# SEE THE OPENDIRECTORYD(8) MAN PAGE FOR ADDITIONAL INFORMATION ABOUT
	# OPEN DIRECTORY.
	##
	NOBODY:*:-2:-2:UNPRIVILEGED USER:/VAR/EMPTY:/USR/BIN/FALSE
	...
	...
```

Solution: [to-upper.c](/src/to-upper.c)
