# Enumeration constant

We already know integer constants, character and string constants, a
floating-point constant, constant expression (an expression that involves only
constants).

There is one other kind of constant, the "enumeration constant".  An enumeration
is a list of constant integer values, as in:

```C
enum boolean { NO, YES};
```

The first name has value `0`, the next one `1`, etc.  You can use explicit
values as well.  Unspecified values continue to progress from the last value
specified.  For example:

```C
enum months {
	JAN = 1,
	FEB,
	MAR,
	APR,
	MAY,
	JUN,
	JUL,
	AUG,
	SEP,
	OCT,
	NOV,
	DEC,
};
```

You could also do as follows:

```C
enum weird {
	one = 3,
	two,		// 4
	three = 3,
	four = 0,
	five,		// 1
	six,		// 2
	seven = -1,
	...
}
```

The list consists of *enumerators*.  I.e. both "JAN = 1" and "FEB" are
enumerators.  When used in code, "JAN", "FEB", "MAR" etc. are *enumeration
constants*.  The values of enumeration constants must fit an `int`.  However,
the implementation may define any integer type to be compatible with the
enumerated type under the condition that all enumeration constants fit the type.
So, the implementation **might** choose a `char` to be compatible with the `enum
boolean` above.

```C
enum white_space { NL = '\n', SP = ' ', TAB = '\t' };
```

The `sizeof` operator applied on an enum itself tells you the integer type used
(`sizeof (enum weird)`), and `sizeof` on any enumeration constant gives you the
same number.

**Names** in different enumerations must be distinct.  In other words, all
enumerators share the same name space.  Values in the same enumerations need not
be distinct, e.g.:

```C
enum not_really_useful { GGG = 1, HHH = 1, GHGH = 0 };
```

Example: :eyes: [enums.c](src/enums.c), [enum-values.c](src/enum-values.c)

## Use `enum`s!

This:

```C
enum commands {
	XXX_LIST,
	XXX_EXTRACT,
	XXX_CREATE
}
```

is so much better than this:

```C
#define	XXX_LIST	0
#define	XXX_EXTRACT	1
#define	XXX_CREATE	2
```

The reason is that the enum is known to the compiler and may be included into
debug symbols.  So, when debugging, you might, if the compiler/debugger support
it, see `XXX_LIST` instead of just `0`.  In the latter case, as the compiler
only see the numbers when compiling the code, you will never see any symbolic
names.  So, seeing the symbols instead of common numbers `0` or `1` is really
helping.
