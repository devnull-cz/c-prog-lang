## File of integers

:wrench: Get a file size using the standard IO API (that is, `lseek(2)` is
prohibited even if you know it).

:wrench: Create an array of `int` values (of arbitrary positive length with
values ranging from `INT_MAX` to `0`), write the array to a file, read the
values into another array and print them to the standard error output.  Between
the writing and reading, the file handle has to remain open.  Use the same file
handle for reading and writing.  Use `xxd(1)` (or `od(1)`, `hexdump(1)`) to
verify the content of the file.  Thus it is handy to start with `INT_MAX` and
e.g. divide by 2 for each successive value.

#solution fopen-binary.c

:wrench: Use the file created by the previous program. Read the values from the
end of the file to the beginning of the file one by one without knowing the file
size and print the numbers to the standard error output.
