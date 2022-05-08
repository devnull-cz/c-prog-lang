# Variable namespace and scope

Identifiers fall into several namespaces that do not interfere with one
another.

These distinct classes are:

- objects, functions, `typedef` constants
- labels
- tags of structures or unions, and enumerations
- members of a structure or union individually

The "individual" part means each structure or union has its own namespace.  So,
you can have two different structures, each using the same member names.

#source identifier-namespace.c
