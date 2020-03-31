# `err`() family of functions

- not defined by any standard however handy
- present in BSD, glibc (= Linux distros), Solaris, macOS, etc.
- use the `<err.h>` include, see the err(3) man page
- this is especially handy when working with I/O
- instead of writing:

```C
if (error) {
	fprintf(stderr, "error occured: %s\n", strerror(errno));
	exit(1);
}
```

- write the following

```C
if (error)
     err(1, "error occured: ");
```

- notice that a newline is inserted automatically at the end of the error
  message.
- or for functions that do not modify the `errno` value, use the *x* variant:

```C
if (some_error)
	errx(1, "ERROR: %d", some_error);
```

- there's also `warn()`/`warnx()` that do not exit the program
