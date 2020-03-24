# File API

part of the standard since C90

# Opening/closing

- `fopen` opens the file and returns opaque handle (pointer)
  - the `mode` argument controls the behavior: read, write, append
  - write mode creates the file
- `fclose` closes the handle.

# I/O

- `fprintf`
- `fputs`
- `fputc`
- `fread`
- `fwrite`

# Seeking

- `fseek`
- `ftell`

:wrench: get a file size using the standard IO API (that is, `lseek(2)` is
prohibited even if you know it).
