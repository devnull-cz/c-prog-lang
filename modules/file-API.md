# File API

Part of the standard since C90.

## Opening/closing

- `fopen("path", "mode")` opens a file and returns a pointer to an opaque `FILE`
  type.  That pointer serves as a handle.
	- getting `NULL` means an error
	- the `mode` argument controls the behavior: read (`r`), write (`w`),
	  append (`a`)
		- the `+` adds the other mode (write for read and vice versa,
		  read for append).
	  - write mode `w` creates the file if it does not exist, and truncates
	    it if it does exist
#module c99-standard.md the standard)
	- `fclose` closes the handle
		  - important to avoid resource leak (`fopen` can allocate both
		    memory and file descriptor)
```
FILE *fp;

/* Choose any other file you have on your system. */
if ((fp = fopen("/etc/passwd", "r")) == NULL)
	err(1, "fopen");

/* process the file... */

if (fclose(fp) != 0)
	err(1, "fclose failed");
```

- the `b` binary mode usually does not have any effect (see
- `freopen` can be used to associate the standard streams (`stderr`, `stdin`, or
  `stdout`) with a file
	- that means e.g. reading the standard input would automatically read
	  from a specific file, if you wanted that
	- `printf(...)` is equivalent to `fprintf(stdout, ...)`.  However, you
	  can print directly to `stderr` with `fprintf`

```C
fprintf(stderr, "Error happened: %s\n", "some error");
```

:wrench: write a code that opens the same file in an cycle (until `fopen()`
fails) without calling `fclose()` on the handle. After how many iterations does
it fail on your system?

#source fopen-leak.c

## I/O

- `fprintf` - `printf` to a stream
- `fscanf`
	  - basically parses text input from a stream according to format string
	  - except the format string all the parameters must be pointers
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

## Read a file

`fread`() reads a selected number of items of a given size to memory.  We can
use either an array or we can directly read to a variable through an operator
address-of.  In our case, we will be reading a file byte by byte, so we can give
`fread`() just an address of a character variable.

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
mind the 2nd argument is size of the element read, and the 3rd argument is how
many elements we read in one call.  Remember that using an array name `a` is the
same as `&a[0]`.  For example:

```C
char a[16];
...
while ((n = fread(a, 1, sizeof (a), fp)) > 0) {
	/* process the bytes here */

	/* if we read less than requested, we hit end of file */
	if (n < sizeof (a))
		break;
}
```

Check the solution here:
#solution read-file2.c

Also check manual page for `fread`() and ignore for now that the 1st argument is
of type `void *`, we will get there later.  As mentioned above, you can safely
put there an array or an address of a variable.

:wrench: Check the man page for `fwrite`() and modify the code so that what is
read from the file you write to some other file.  Do not remember to open the
output file for writing.  All the details are in the man page.

## Seeking

When reading/writing to a file using the above function, the current position
changes accordingly.  However, the position can be manipulated without
performing any I/O.

- `fseek` - moves the position
	- the `whence` parameter has 3 possible values and makes the `offset`
	  parameter relative to:
		- `SEEK_SET` - the beginning of the file
		- `SEEK_END` - the end of the file
		- `SEEK_CUR` - the current location of the cursor in the file
- `ftell` - get current position in the file
