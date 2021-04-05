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

:wrench: task: create a text file where each line begins with integer followed
by space and a string (`echo "1 foo" > file.txt; echo "2 bar" >> file.txt`).
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

:wrench: get a file size using the standard IO API (that is, `lseek(2)` is
prohibited even if you know it).

:wrench: write array of `int` values (use an arbitrary positive count with values
ranging from `INT_MAX` to `0`) to a file and read the values into another array
and print them to the standard error output without closing the file in between
the writing and reading. Use `od(1)` to verify the content of the file (thus it
is handy to start with `INT_MAX` and e.g. divide by 2 for each successive
value).
#source fopen-binary.c

:wrench: use the file created by the previous program. Read the values from the
end of the file to the beginning of the file one by one without knowing the file
size and print the numbers to the standard error output.
