## :wrench: alternating bits detection

Task: detect if binary representation of an `unsigned int` has alternating bits
in the whole width of the type.  (e.g. `01010101` if the type was `char`).

The answer from the program will be yes/no (printed to standard output).

Start with naive/straightforward implementation, i.e. traverse all the bits
(O(n) time) and use bit operations/arithmetics.

Note: this can be done in O(1) time by comparing the value with 2 constants.

#solution altbits.c
