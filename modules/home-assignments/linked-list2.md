## Linked list, part II.

(Note: this assignment was given in one of the previous years as the assignment
for the final in-person test with the 90 minute limit).

```C
/*
 * Create a set of functions for manipulating a linked list.  The program
 * accepts input commands as command line arguments and executes them.  New
 * elements are always appended to the list and any item is always removed from
 * the head.  Keep pointers to the first list item (head) and the last one
 * (tail).
 *
 * Commands are: create a list, insert an item, remove an item, and print the
 * list.  It is mandatory to create a list before doing anything else.
 *
 *   create a list:		C
 *   insert an item:		I<nnn>
 *   remove an item:		R
 *   print a list:		P
 *
 * Do reasonable checking for dealing with invalid input.  See below.
 *
 * Example:
 *
 *   $ ./a.out C I1 I2 I3 I4 I5 P R P I6 P I7 P R P R P R P R R R P I88 P R P
 *   List: 1 2 3 4 5
 *   List: 2 3 4 5
 *   List: 2 3 4 5 6
 *   List: 2 3 4 5 6 7
 *   List: 3 4 5 6 7
 *   List: 4 5 6 7
 *   List: 5 6 7
 *   List: EMPTY
 *   List: 88
 *   List: EMPTY
 *
 *   $ ./a.out C R
 *   a.out: Cannot remove an item from an empty list.
 *
 *   $ ./a.out C P
 *   List: EMPTY
 *
 *   $ ./a.out C L
 *   a.out: Wrong command: L
 *
 *   $ ./a.out C C
 *   a.out: List already created, exiting.
 *
 *   $ ./a.out I88
 *   a.out: List not created yet.
 */
```

#source linked-list.c
