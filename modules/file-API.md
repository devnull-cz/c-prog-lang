# File API

Part of the standard since C90.

## Opening/closing

- `fopen` opens a file and returns an opaque handle (pointer)
  - `NULL` pointer means error
  - the `mode` argument controls the behavior: read, write, append
    - the `+` adds the other mode (write for read and vice versa, read for append)
  - write mode creates the file if it does not exist
  - the `b` binary mode usually does not have any effect (see
#module c99-standard.md the standard)
- `fclose` closes the handle
  - important to avoid resource leak (`fopen` can allocate both memory and file
    descriptor)
- `freopen` can be used to associate the standard streams (`stderr`, `stdin`, or
  `stdout`) with a file

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
- `fputc`/`fgetc` - send/read `char` to/from a stream
- `fwrite`/`fread` - for writing/reading binary data (such as structures or raw
  numeric types)

:wrench: create a text file where each line begins with integer followed
by space and a string, e.g.:
```
42 towel
13 dwarfs and Snow White
```
Read the file using `fscanf()` and print the values (i.e. integer and a string)
from each line to standard output.

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
