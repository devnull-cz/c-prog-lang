# Basics

- to get the source code for the examples, do the following on the command line.
  However, do not look at it until you write your own version.  Just compile and
  run it first to see what each program does.

	```
	git clone https://github.com/devnull-cz/c-prog-lang.git
	```

- each program **must** have a `main()` function
	- well, there are exceptions: see
#module freestanding-environment.md freestanding environment
	  if interested.  Another exception is implementation defined.  It is
	  out of scope for this seminar though.

- string literals (AKA string constants): #source printf.c

- use the `return` operator to return a function value
	- in the `main()` funtion, return exits the program
	- in the shell, use `echo $?` to see the return value of the most
	  recently run program on the foreground
	- only the least significant byte taken as an unsigned integer (0-255)
	  is relevant
	- #source return.c
	- if you do not use return from main() and the ending `}` is reached,
	  the program returns 0 (in C89 it would be a random number though).

- you must declare a variable before you can use it
	- #source declaration.c

- `printf()` can use *conversion specifications*, each starts with `%`
	- `int i; printf("%d\n", i);`
		- a character like `d` is called a *conversion specifier*
	- see `man 3 printf` for the gory details
	- number of conversions must match the number of arguments
		- #source printf2.c
		- the compiler may or may not warn you but it will let you do it
		  (use `-Werror` to treat warnings as errors).  With `gcc`, use
		  the `-Wall` option to show all warnings.
		- it will print garbage for conversions without a matching
		  argument -- whatever is on the stack (x86 32 bit) or in a
		  specific register (x86 64 bit) is printed.

- you can declare and initialize a variable at the same time
	- `int i = 13;`
	- `13` is called an *initializer*
	- you can initialize a variable with another variable, and so on
```C
	int i = 13;
	int j = i;
	int k = i + j;
```

- arithmetics
	- `==` is for equality, `=` for an assignment
		- memory was precious in the past, and programs usually had more
		  assignments than comparisons
	- `+`, `-`, `/`, `*`
	- `++`, `--`
		- `int i; i = 13; printf("%d\n", i++);` will print `13` and then
		  increment `i`
		- `int i; i = 13; printf("%d\n", ++i);` will first increment `i`
		  then print `14`
		- `++i` is an expression, not a variable, so you cannot assign to it
			- this will not compile: `++i = 13;`
	- #source arithmetics.c

- save for an assignment, anywhere you can use a variable, you can use an
  expression
	```C
	printf("%d\n", 100 * 2);
	```

- if both operands are ints, the result is an int
	- `printf("%d\n", 9 / 5)` will print `1`

- while loop
	- #source while.c

- if statement
	- #source if.c

- floating point numbers
	- #source float.c
	- see the optional minimum field width and precision
	- experiment!!!

- :wrench: print out a table for inch to centimeter conversion for 1-9 inches,
  use `int`s only (not `float`s)
	- #source inches-to-cm.c
	- use `\t` escape sequence for printf to print tabelators
	- like this:
	```C
	printf("\tX\tY\n");
	```
	- example output:
	```
	Inches	Centimeters
	1	2
	2	5
	3	7
	4	10
	5	12
	6	15
	7	17
	8	20
	9	22
	```

- :wrench: use floats for the conversion code
	- #source inches-to-cm2.c
		- '\t' in a string will print a tab
		- `6` is the minimum field width 
		- `.2` is the precision
		- see the printf(3) man page for details
	- example output:
	```
	Inches	Centimeters
	1	  2.54
	2	  5.08
	3	  7.62
	4	 10.16
	5	 12.70
	6	 15.24
	7	 17.78
	8	 20.32
	9	 22.86
	```

- :wrench: print fahrenheit to centigrade table.  Use floats.
	- the formula to convert F to C is: (F - 32) × 5/9.  E.g. 72F is 22.22C.
	- #source fahr-to-cent.c
	- example output:
	```
	  0	-17.78
	 20	 -6.67
	 40	  4.44
	 60	 15.56
	 80	 26.67
	100	 37.78
	120	 48.89
	140	 60.00
	160	 71.11
	180	 82.22
	200	 93.33
	220	104.44
	240	115.56
	260	126.67
	280	137.78
	```
