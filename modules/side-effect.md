# Side effect

C99, *5.1.2.3 Program execution*:

>"Accessing a volatile object, modifying an object, modifying a file, or calling
a function that does any of those operations are all side effects,11) which are
changes in the state of the execution environment.  Evaluation of an expression
may produce side effects.  At certain specified points in the execution sequence
called sequence points, all side effects of previous evaluations shall be
complete and no side effects of subsequent evaluations shall have taken place.
(A summary of the sequence points is given in annex C.)"
