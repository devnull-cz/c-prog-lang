# Object

See *3. Terms, definitions, and symbols* for the full list of terms.
an *object* is defined in 3.14.

An *object* is a region of data storage in the execution environment, the
contents of which can represent values.

For the definition of an *execution environment*, one could go to the *5.
Environment* chapter of the spec but in our situation that is not that
important.

When an object is interpreted as having a specific type, you get the object's
*value* (3.17).  For example, when you interpret a float object as an integeter,
you get a different value from interpreting a float object as a float.

An object is referenced by an expression. See
#module expressions.md basic information on expressions.
For example, in a simple case, an object is referenced by an identifier, which
itself is an expression.
