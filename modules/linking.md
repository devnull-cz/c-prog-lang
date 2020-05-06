# Linking objects

Larger programs are often split into many source code files. One can create the
binary like so:
```
  cc -o binary foo.c bar.c ...
```
and it will work however the files will be compiled every time even though they
were not changed.

To save time the files are usually compiled individually and then linked
into the binary using _runtime linker_ (sometimes called _link editor_),
a program usually called `ld`. This program also takes care of adding
dependencies on dynamic libraries to the resulting binary.

It works like this (assuming all source code files changed):
```
  cc -c foo.c
  cc -c bar.c
  ...
  cc -o binary foo.o bar.o ...
```

Note that the program `ld` was not invoked directly, it is the compiler that
serves as a `ld` wrapper as it needs to add more object files with C runtime
under the hood. So in reality the compiler accepts some linker options
(and passes them through) to make it easier for the programmer.

For GCC you can use the `-###` option to see what commands are executed during
compilation.
