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

```
y = sqrt(MYRAD * MYRAD - x * x);
```

Obviously, there are more ways how to do it.

- the easiest way is to use a two-dimensional array and go through the `x` axis
  and fill the corresponding `y` value before printing out the array line by
  line.
  - to print the array, instead of printing it a character by character, we can
    also use array lines as strings if we terminate each line first with a `\0`.
- you could print the output line by line, that is, figure out what to print on
  each line.  You do not need a two-dimensional array then, and speaking of
  which, not even an array at all.

You can find the `sqrt()` function declaration in `<math.h>`.

On Linux, you will need to link with the math library to get the `sqrt()`
function code, ie:

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

Solution:
#source circle.c
