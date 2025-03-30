# File API

Part of
#module c99-standard.md the standard
since C90.

## Opening/closing

- The `fopen("path", "mode")` opens a file and returns a pointer to an opaque
  `FILE` type.  That pointer serves as a handle.
	- An "opaque type" means it is something the programmer does not need
	  (and should not need) to care what the type actually is.  In this
	  case, it is not relevant what `FILE` actually is.
	- Function returns `NULL` on error.
	- The `mode` argument controls the behavior: read (`r`), write (`w`),
	  append (`a`).
		- The `+` adds the other mode (write for read and vice versa,
		  read for append).
	  - Write mode `w` creates the file if it does not exist, and truncates
	    it if it does exist.
	- The `fclose` closes the handle
		  - Important to avoid resource leak (`fopen` can allocate both
		    memory and file descriptor).
```C
FILE *fp;

/* Choose any other file you have on your system. */
if ((fp = fopen("/etc/passwd", "r")) == NULL)
	err(1, "fopen");

/* process the file... */

if (fclose(fp) != 0)
	err(1, "fclose");
```

- The `b` binary mode usually does not have any effect.
- The `freopen` can be used to associate the standard streams (`stderr`,
  `stdin`, or `stdout`) with a file.
	- That means e.g. reading the standard input would automatically read
	  from a specific file, if you wanted that.
	- `printf(...)` is equivalent to `fprintf(stdout, ...)`.  However, you
	  can also print directly to `stderr` with `fprintf`.

```C
fprintf(stderr, "Error: %s\n", "some error");
```

:wrench: Write a code that opens the same file in an cycle (until `fopen()`
fails) without calling `fclose()` on the handle. After how many iterations does
it fail on your system?

#solution fopen-leak.c

## I/O

- `fprintf` works like `printf` but prints to a specific stream
- `fscanf`
	- Basically parses text input from a stream according to format string
	- After the format string, all argument must be pointers.
- `fputs`/`fgets` - send/read string to/from a stream

```C
fputs("hello, world\n", stdout);
```

- `fputc`/`fgetc` - send/read `char` to/from a stream

```C
fputc('x', stderr);
```

- `fwrite`/`fread` - for writing/reading binary data (such as structures or raw
  numeric types)

- `feof`/`ferror` - determine if the last I/O operation hit end of file or
  error.

## Read a file

The `fread`() reads a selected number of items of a given size to memory.  We
can use either an array or we can directly read to a variable through an
operator address-of.  In our case, we will be reading a file byte by byte, so we
can give `fread`() just an address of a character variable.

You can ignore the `restrict` keyword, it is intended as a hit for a compiler
optimization, and also just accept now that we can assign any pointer to a `void
*` pointer.

```C
size_t fread(void *restrict ptr, size_t size, size_t nmemb,
	     FILE *restrict stream);
```

Now we will read the file in chunks of one byte only.  Therefore we can use an
`address-of` operator on a `char` object.

```C
char c;
FILE *fp;

/* Choose any other file you have on your system. */
if ((fp = fopen("/etc/passwd", "r")) == NULL)
	err(1, "fopen");

/*
 * fread() returns a number of *items* read.  In our case, it's the same as
 * number of bytes as we read it one byte at a time.
 */
while (fread(&c, sizeof (c), 1, fp) == 1) {
	putchar(c);
}

fclose(fp);
```

#source read-file.c

:wrench: Note that you could read more characters at a time.  However, keep in
mind the 2nd argument is the size of the element read, and the 3rd argument is
how many elements we read in one call.  Remember that using an array name `a` is
the same as `&a[0]`.  For example:

```C
char a[16];
/*
 * Do not use "16" instead of nelem below to avoid changing more than one place
 * when you replace 16 with anything else.
 */
size_t nelem = sizeof (a) / sizeof (a[0]);
...

while ((n = fread(a, sizeof (a[0]), nelem, fp)) > 0) {
	/* Process the bytes here. */
	/* ... */

	/*
	 * If we read less elements than requested, we hit an end of file or
	 * error.
	 */
	if (n < nelem)
		break;
}
```

What could happen if reading bytes into character array and the 2nd and 3rd
arguments are swapped?

#source read-file2.c

Check manual page for `fread`() and ignore for now that the 1st argument is
of type `void *`, we will get there later.  As mentioned above, you can safely
put there an array or an address of a variable.

:wrench: Check the man page for `fwrite`() and modify the code so that what is
read from the file you write to some other file. The file should be created if
it does not exist. If it exists, its contents should be truncated.  Do not
forget to open the output file for writing.  All the details are in the man
page.

#solution file-copy.c

## Seeking

When reading/writing to a file using the above function, the current position
changes accordingly.  However, the position can be manipulated without
performing any I/O.

- `fseek` moves the position.
	- The `whence` parameter has 3 possible values and makes the `offset`
	  parameter relative to:
		- `SEEK_SET` - the beginning of the file
		- `SEEK_END` - the end of the file
		- `SEEK_CUR` - the current location of the cursor in the file
- `ftell` returns the current position in the file.

:wrench: By seeking, write code that creates a file that has every
4-th character a upper case letter of alphabet (`A` to `Z`) and then
prints the contents of the file byte by byte.  Print the non-printable bytes
in hexadecimal (with `0x` prefix).

#solution file-AZ.c
