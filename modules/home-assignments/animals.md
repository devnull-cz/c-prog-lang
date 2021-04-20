## animals: maximum number of legs

implement:
```C
      struct animal *maxlegs(struct animal *, size_t len);
```
that will use the `getlegs()` function and will return an animal with highest
leg count. Return pointer to the structure (= array element) from the function.

The `main()` function (in separate file) will define an array of animals and
will call `maxlegs()`.  The name of the animal with maximum number of legs will
be printed to standard output.

Note: does the original structure change if the structure returned from the
function was modified within the function? How to fix this ?

code:
  - #solution animal\_maxlegs.c
  - #solution maxlegs.c
  - #solution animals.h
  - #solution animal.h

## :wrench: animal sorting

:wrench: Task: sort the array by number of legs, print it out to standard
output.

:wrench: Task: sort the array by the animal name. Print it out to standard
output.  Use `strcmp()` to do the comparison of names.

Make the comparison functions static.

Use the standard libc sort function qsort(3).  Check the manual page on how it's
used.  You will need to define a callback function that the qsort() function
will use to compare two array elements.

Make the program to accept an argument (0 or 1) and run the sorting function
based on that.

code:
  - #solution animal-sort.c
  - #solution animals.h
  - #solution animal.h

