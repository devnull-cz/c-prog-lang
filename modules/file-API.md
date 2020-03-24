# File API

part of the standard since C90

# Opening/closing

- `fopen` opens the file and returns opaque handle (pointer)
  - `NULL` pointer means error
  - the `mode` argument controls the behavior: read, write, append
    - the `+` adds the other mode (write for read and vice versa, read for append)
  - write mode creates the file
- `fclose` closes the handle
  - important to avoid resource leak (it can allocate both memory and file descriptor)

:wrench: write a code that opens the same file in an cycle (until `fopen()` fails) without calling `fclose()` on the handle. After how many iterations does it fail on your system ?

:eyes: code: [fopen-leak.c](/src/fopen-leak.c)

# I/O

- `fprintf` - `printf` to a stream
- `fscanf` 
  - basically parses text input from a stream according to format string
  - except the format string all the parameters must be pointers
- `fputs` - send string to a stream
- `fputc` - send `char` to a stream
- `fread`
- `fwrite`

# Seeking

- `fseek`
- `ftell`

:wrench: get a file size using the standard IO API (that is, `lseek(2)` is
prohibited even if you know it).
