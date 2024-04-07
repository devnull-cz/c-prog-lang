## Print a circle

Print a circle of a chosen radius.  Use a define for the radius so that you can
test other sizes.  This is for 12, for example:

```
$ ./a.out
            *
        **** ****
      **         **
     *             *
    *               *
   *                 *
  *                   *

 *                     *



*                       *



 *                     *

  *                   *
   *                 *
    *               *
     *             *
      **         **
        **** ****
            *
```

Hint: an equation for a circle is `x^2 + y^2 = MYRAD^2`, ie.

```C
y = sqrt(MYRAD * MYRAD - x * x);
```

Obviously, there are more ways how to do it.

- The easiest way is to use a two-dimensional array and go through the `x` axis
  and fill the corresponding `y` value before printing out the array line by
  line.
	- To print the array, instead of printing it a character by character,
	  we can also use array lines as strings if we terminate each line first
	  with a `\0`.
- You could print the output line by line, that is, figure out what to print on
  each line.  You do not need a two-dimensional array then, and speaking of
  which, not even an array at all.

You can find the `sqrt()` function declaration in `<math.h>`.  You can also use
`memset()` from `string.h` to set a piece of memory to a specific byte (=
character).

On Linux and possibly other systems, you will need to link with the math library
to get the `sqrt()` function code, i.e:

```
$ gcc -lm warm-up.c
```

An extension: fill the circle up.

```
$ ./a.out
            *
        *********
      *************
     ***************
    *****************
   *******************
  *********************
  *********************
 ***********************
 ***********************
 ***********************
 ***********************
*************************
 ***********************
 ***********************
 ***********************
 ***********************
  *********************
  *********************
   *******************
    *****************
     ***************
      *************
        *********
            *
```

#solution circle.c

A simplified solution:

#solution circle-simplified.c
