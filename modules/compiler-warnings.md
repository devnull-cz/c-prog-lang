# Compiler warnings

- Each compiler has its own set of warnings that usually give a clue that
  something strange and potentially harmful can happen.
	- There are differences between various compilers.
	- We will focus on GCC here.
	- During the old days the tool producing these warnings was called
	  `lint` that had to be run separately (there was not enough memory to
	  do both at once).  Now those extra checkes are usually part of the
	  compiler itself.

	- The basics: use `-Wall -Wextra`
		- `-Wall` catches things like missing return value from a
		  function that should return one.

#source no-return.c

	- There are many places where a beginner can shoot himself into a foot
	  by not knowing the language intricacies.
		- E.g. variable cannot be modified more than once between
		  sequencing points (C99 6.5 paragraph 2). The
		  `-Wsequence-point` that is included in `-Wall` warns about
		  that.

#source sequence-point-violation.c

	- The `-Wshadow` can catch shadow variables overriding:

#source shadow.c
#source shadow-block.c

	- All or specific warnings can be turned into errors: `-Werrror` or
	  `-Werror=<insert_specific_error>`, respectively.
		- Unless the warnings contain false positives (and those can
		  usually be suppressed) this will help to avoid troubles later.

	- There are other means to check for correctness (static/dynamic
	  analysis), more on those later.

## :wrench: Use the options

Go through the programs written so far and run the compiler using the `-Wall
-Wextra` options.
	- What kind of problems did you discover ? how to fix them ?
		- See e.g. #source whole-array.c example above (where only
		  `-Wextra` gives some clue)

Explore the compiler documentation for more helpful options.  Over the time you
will find a set of warning options that will serve you well.
