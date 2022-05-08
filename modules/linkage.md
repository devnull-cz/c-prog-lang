# Internal vs external linkage

Static objects with the keyword `static` are of internal linkage, meaning they
are not seen from other compilation units.  Static objects without the keyword
`static` are implicitly external.

Note that global variables in always in the static storage class, and the
following global variable is visible only from within the file where it is
defined because of the `static` keyword:

```C
static int x_global;

int
main(void)
{
	// ...
}
```

As we mentioned before, `static` is really an overloaded word/keyword in C and
may lead to confusion.

However, the following global variable (of the static storage class) is of
external linkage, meaning it is visible from other compilation modules (=
files).

```C
int x_global;

int
main(void)
{
	// ...
}
```

Use `extern` keyword for objects that are defined in a different compilation
unit.

Example:

	$ cc linkage.c ext.c
	Undefined symbols for architecture x86_64:
	  "_si", referenced from:
	      _main in linkage-917564.o
	ld: symbol(s) not found for architecture x86_64
	clang: error: linker command failed with exit code 1 (use -v to see invocation)

#source linkage.c
#source ext.c

Also note that each object must have exactly one definition.  For objects with
internal linkage, this rule applies separately to each translation unit, because
internally-linked objects are unique to a translation unit.
