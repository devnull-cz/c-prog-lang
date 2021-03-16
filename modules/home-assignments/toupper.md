## :wrench: to upper

Convert small characters to upper chars in input.  Use the fact that a-z and
A-Z are in two consequtive sections of the ASCII table.

Use the else branch:
```
	if (a) {
		...
	} else {
		...
	{
```
Expected output:
```
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

Solution: #source to-upper.c
