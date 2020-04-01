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
          if interested.  It is out of scope for this seminar though.

- string literals:
#source printf.c

- use the `return` operator to return a function value
	- in the `main()` funtion, return exits the program
	- in the shell, use `echo $?` to see the return value of the most
	  recently run program on the foreground
	- only the least significant byte taken as an unsigned integer (0-255)
	  is relevant
	- 
#source return.c
	- if you do not use return from main() and the ending } is reached, the
	  program returns 0 (in C89 it would be a random number though).

- you must declare a variable before you can use it
	- :eyes: [declaration.c](/src/declaration.c)

- `printf()` can use *conversion specifications*, each starts with `%`
	- `int i; printf("%d\n", i);`
		- a character like `d` is called a *conversion specifier*
	- see `man 3 printf` for the gory details
	- number of conversions must match the number of arguments
		- :eyes: [printf2.c](/src/printf2.c)
		- the compiler will warn you but it will let you do it (use
		  `-Werror` to treat warnings as errors)
		- it will print garbage for conversions without a matching
		  argument (whatever is on the stack is printed).

- you can declare and initialize a variable at the same time
	- `int i = 13;`
	- `13` is called an *initializer*
	- you can initialize a variable with an expression as well
		- `int i = 13; int j = i;`

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
	- :eyes: [arithmetics.c](/src/arithmetics.c)

- save for an assignment, anywhere you can use a variable, you can use an
  expression
	```C
	printf("%d\n", 100 * 2);
	```

- if both operands are ints, the result is an int
	- `printf("%d\n", 9 / 5)` will print `1`

- while loop
	- :eyes: [while.c](/src/while.c)

- if statement
	- :eyes: [if.c](/src/if.c)

- floating point numbers
	- :eyes: [float.c](/src/float.c)
	- see the optional minimum field width and precision
	- experiment!!!

- :wrench: print out a table for inch to centimeter conversion
	- :eyes: [inches-to-cm.c](/src/inches-to-cm.c)
	- use "\t" escape sequence for printf to print tabelators
	- like this:
	```C
	printf("\tX\tY\n");
	```

- :wrench: use floats for the conversion code
	- :eyes: [inches-to-cm2.c](/src/inches-to-cm2.c)
		- '\t' in a string will print a tab
		- `6` is the minimum field width 
		- `.2` is the precision
		- see the printf(3) man page for details

- :wrench: print fahrenheit to centigrade table.  Use floats.
	- :eyes: [fahr-to-cent.c](/src/fahr-to-cent.c)
