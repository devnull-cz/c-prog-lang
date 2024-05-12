# Linking objects

Larger programs are often split into many source code files. One can create the
binary as follows:

```
cc -o binary foo.c bar.c ...
```

and it will work however the files will be compiled every time even though they
were not changed.

To save time the files are usually compiled individually and then linked into
the binary using a _runtime linker_ (sometimes called a _link editor_, or just a
*linker*), a program usually called `ld`. This program also takes care of adding
dependencies on dynamic libraries to the resulting binary.

It works like this (assuming all source code files changed):

```
cc -c foo.c
cc -c bar.c
...
cc -o binary foo.o bar.o ...
```

Do not confuse the runtime linker with *dynamic linker*, usually called
`ld.so`. See its manual page for more information.

Note that the program `ld` was not invoked directly, it is the compiler that
serves as an `ld` wrapper as it needs to add more object files with the C
runtime under the hood. So in reality the compiler accepts some linker options
(and passes them through) to make it easier for the programmer.

For GCC you can use the `-###` option to see what commands would actually be
executed during compilation.  Use `-v` to get the same debugging information but
also execute the commands.

Usually it is desirable to avoid rebuilding objects unnecessarily, especially
when there is a large number of source files. This is usually done via set of
rules that establish dependencies. The most common tool for that is `make` and
`Makefile` is its configuration file that drives the compilation.
