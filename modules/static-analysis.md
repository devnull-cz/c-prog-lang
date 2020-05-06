## Static analysis

- compile time warnings are inherently limited
  - they can detect wide range of errors (format strings, offer missing include
    files, detect simple buffer overflows, ...)

#source fmt-string-invalid.c
#source buf-overflow.c

  - however fail to cover all corner cases

- static analysis tools hook into compiler and can follow all code paths
  - by constructing graph of code blocks
  - this is useful also for "taint analysis" - following potentially
    unsanitized data input across all code paths to determine if it can be used
    to exploit code deficiencies
  - the method has its drawbacks - false positives, can be foiled sometimes
    because it does not understand enough context and program internals

- Clang: the `scan-build` script is front-end to the library performing checks,
         accepts compilation line as argument
         - the compilation line can be simple compiler invocation and also make

#source buf-overflow-func.c

  - when compiled with `-Wall -Wextra` no warnings/errors are reported
  - when run, it usually does (depends on compiler/system) not produce any
    warnings and happily prints the corrupted array
    - try to compile with `-DBUFFER_SIZE=128` and the result might be different
      due to stack smashing detection supplied by the compiler
      - if the program is compiled with `-fno-stack-protector` , the stack
	canary is not added and the program normally (sic!) exits with
	segmentation fault
      - try with different compilers (gcc, clang)

Run: `scan-build clang buf-overflow.c`

Note: works with gcc too

Task: write a program that accesses memory allocated on the heap after it is
      freed. See if scan-build static analyzer can detect it.
      Modify the program to return the allocated memory from a function
      and then free + modify it in main. Does scan-build still detect this
      use-after-free bug ?

#source use-after-free.c
