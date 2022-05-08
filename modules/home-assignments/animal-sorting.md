## :wrench: Animal sorting

You may remember
#module home-assignments/animals.md working with an animal structure.

Use the same structure for this assignment.

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

Bonus: sort the animals based on both name and number of legs.
