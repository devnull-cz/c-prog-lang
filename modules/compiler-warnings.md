# Compiler warnings

- each compiler has its own set of warnings that usually give a clue that
  something strange and potentially harmful can happen.
  - there are differences between various compilers
  - will focus on GCC here
  - during the old days the tool producing these warnings was called 'lint'
    that had to be run separately

  - the basic: `-Wall -Wextra`
    - `-Wall` catches things like missing return value from a function that
      should return one

      code: #source no-return.c

    - there are many places where a beginner can shoot himself into a foot
      by not knowing the language intricacies.
      - e.g. variable cannot be modified more than once between sequencing
	points. The `-Wsequence-point` that is included in `-Wall` warns about
	that

      code: #source sequence-point-violation.c

  - the `-Wshadow` can catch shadow variables overriding:

    code: #source shadow.c
    #source shadow-block.c

  - all or specific warnings can be turned into errors: `-Werrror` or
    `-Werror=<insert_specific_error>` , respectively
    - unless the warnings contain false positives (and those can usually be
      suppressed) this will help to avoid troubles later

  - there are other means to check for correctness (static/dynamic analysis),
    more on those later

## :wrench: Use the options

Go through the programs written so far and run the compiler using the
  `-Wall -Wextra` options.
  - what kind of problems did you discover ? how to fix them ?
    - see e.g. #source whole-array.c
      example above (where only `-Wextra` gives some clue)

Explore the compiler documentation for more helpful options.
Over the time you will find a set of warning options that will serve you well.
