# `err`() family of functions

- Not defined by any standard however handy.
- Present in BSD, glibc (= Linux distros), Solaris, macOS, etc.
- Use the `<err.h>` include, see the err(3) man page.
- This is especially handy when working with I/O.

Instead of writing:

```C
if (error) {
	fprintf(stderr, "Error: %s\n", strerror(errno));
	exit(1);
}
```

Use the following.  It will append ": " string and then the error message
itself, based on the value of `errno`.

```C
if (error)
     err(1, "Error");
```

- Notice that a newline is inserted automatically at the end of the error
  message.
- For functions that do not modify the `errno` value, use the *x* variant:

```C
if (some_error)
	errx(1, "ERROR: %d", some_error);
```

There's also `warn()`/`warnx()` that do not exit the program.
