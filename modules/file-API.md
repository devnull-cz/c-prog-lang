# File API

part of the standard since C90

# Opening/closing

- `fopen` opens the file and returns opaque handle (pointer)
  - `NULL` pointer means error
  - the `mode` argument controls the behavior: read, write, append
    - the `+` adds the other mode (write for read and vice versa, read for append)
  - write mode creates the file
  - the `b` binary mode does not usually have any effect (see the standard)
- `fclose` closes the handle
  - important to avoid resource leak (it can allocate both memory and file descriptor)
- `freopen` can be used to associate the standard streams (`stderr`, `stdin`, or `stdout`) with a file

:wrench: write a code that opens the same file in an cycle (until `fopen()` fails) without calling `fclose()` on the handle. After how many iterations does it fail on your system ?

:eyes: code: [fopen-leak.c](/src/fopen-leak.c)

# I/O

- `fprintf` - `printf` to a stream
- `fscanf` 
  - basically parses text input from a stream according to format string
  - except the format string all the parameters must be pointers
- `fputs`/`fgets` - send/read string to/from a stream
- `fputc`/`fgetc` - send/read `char` to/from a stream
- `fwrite`/`fread` - for writing/reading binary data (such as structures or raw numeric types)

# Seeking

When reading/writing to a file using the above function, the current position changes accordingly.
The position can be manipulated without performing any I/O.

- `fseek` - moves the position
  - the `whence` parameter has 3 possible values and makes the `offset` parameter relative to:
    - `SEEK_SET` - the beginning of the file
    - `SEEK_END` - the end of the file
    - `SEEK_CUR` - the current location of the cursor in the file
- `ftell` - get current position in the file

:wrench: get a file size using the standard IO API (that is, `lseek(2)` is
prohibited even if you know it).

:wrench: write array of `int` values (use arbitrary positive count with values ranging from `INT_MAX` to `0`) to a file and read the values into another array and print them to standard error output without closing the file in between the writing and reading. Use `od(1)` to verify the content of the file (thus it is handy to start with `INT_MAX` and e.g. divide by 2 for each successive value). :eyes: code [fopen-binary.c](/src/fopen-binary.c)

:wrench: use the file created by the previous program. read the values from the end of the file to the beginning of the file one by one without knowing their count and print them to standard error output.
