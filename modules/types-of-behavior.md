# Types of behavior in C

From C99, Annex J.

## 3. Terms, definitions, and symbols

...

### 3.4.1

*implementation-defined behavior* is unspecified behavior where each
implementation documents how the choice is made.

An example of implementation-defined behavior is the propagation of
the high-order bit when a signed integer is shifted right.

...

### 3.4.3

*undefined behavior* is behavior, upon use of a nonportable or erroneous program
construct or of erroneous data, for which this International Standard imposes no
requirements.

Possible undefined behavior ranges from ignoring the situation completely with
unpredictable results, to behaving during translation or program execution in a
documented manner characteristic of the environment (with or without the
issuance of a diagnostic message), to terminating a translation or execution
(with the issuance of a diagnostic message).

An example of undefined behavior is the behavior on integer overflow.

...

### 3.4.4

*unspecified behavior* is use of an unspecified value, or other behavior where
this International Standard provides two or more possibilities and imposes no
further requirements on which is chosen in any instance.

An example of unspecified behavior is the order in which the arguments to a
function are evaluated.

## Notes

See also
#module undefined-behavior.md More Information on Undefined Behavior.
