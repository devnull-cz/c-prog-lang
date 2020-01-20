# Basics

- each program **must** have a `main()` function
	- well, there are exceptions: in a *freestanding environment* (in which
	  C program execution may take place without any benefit of an operating
	  system), the name and type of the function called at program startup
	  are *implementation-defined*.  For example, GRUB.  However, we do not
	  need to worry about that here.  See [C99 standard](c99-standard.md),
	  5.1.2.1, if interested.
	- we will learn about different types of behavior later (like
	  implementation-defined above).  If curious, see
	  [here](behavior-types.md)

- string literals
	- :eyes: [printf.c](/src/printf.c)

- use the `return` operator to return a function value
	- in the `main()` funtion, return exits the program
	- in the shell, use `echo $?` to see the return value of the most
	  recently run program on the foreground
	- only the least significant byte taken as an unsigned integer (0-255)
	  is relevant
	- [return.c](/src/return.c)
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

- anywhere you can use a variable, you can use an expression
	```C
	printf("%d\n", 100 * 2);
	```

- if both operands are ints, the result is an int
	- `printf("%d\n", 9 / 5)` will print `1`

- while loop
	- :eyes: [while.c](/src/while.c)

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
