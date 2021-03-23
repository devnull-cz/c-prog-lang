# Function arguments

Say, what happens if you put a `char` as an argument of a function that accepts
an `int`?  As you might expect, the byte is just assigned to an `int`.

In general, the expressions passed as arguments are evaluated first, then the
value of the resulted type is converted to the parameter type as in assignment.

More on that later.  For more information, see 6.9.1 in
[C99](/modules/c99-standard.md)
