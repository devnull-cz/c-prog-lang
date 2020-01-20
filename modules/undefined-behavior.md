# More Information on Undefined Behavior

For the definition of *undefined behavior*, see [types of behavior in
C](/modules/behavior-types.md).

**Now an important note:** it is not that a small part of a program (statement,
expression, ...) has a result that is not predictable, given that anything could
have happened during the statement execution, **the entire execution of the
program that experienced that undefined behavior is meaningless.**

Not only when writing software for cars, trains, planes, nuclear power plants,
etc., you really have to be aware of that.

More information can be found in [A Guide to Undefined Behavior in C and
C++](https://blog.regehr.org/archives/213).
