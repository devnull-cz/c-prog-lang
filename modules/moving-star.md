# Assignment for the first class

```
  /*
   * Implement a moving star that zick zacks on the same line between some
   * boundary (say 50 character wide).
   *
   * You will only need:
   *
   *	- while loop
   *	- if statement (do not use else)
   *	- printf()
   *	- use a character '\r' to return to the beginning of a line
   *
   *	- use "poll(NULL, 0, <ms>);" to sleep <ms> miliseconds, do not worry
   *	  about not understanding what exactly it does.  To make the compiler
   *	  not complain, use "#include <poll.h>".  Alternatively, you can use
   *	  "sleep(1)" (#include <unistd.h>) but it is too slow then.  For
   *	  example:
   *
   *		poll(NULL, 0, 50);
   *
   *    - you will also need "fflush(stdout)" after each line is printed.  As
   *      standard error is buffered in the C library, the text will generally
   *      not be printed by printf() until a new line is printed, which will
   *      never be the case here. So, the fflush() call makes sure all buffered
   *      text is printed out.
   *
   * We expect something like this, with the star moving between those two
   * column-like barriers:
   *
   * |                                            *     |
   */
```

When you have a working solution, you can check out our code at
`src/moving-star.c`.
