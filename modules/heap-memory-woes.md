# Dynamic allocation induced problems

## Correctness

- Use after free: read/write memory that is part of memory chunk that was free'd
  - *Dangling pointer* is often the cause of this; e.g. a structure contains a
    pointer to heap allocated memory which is freed at some point of time and
    the pointer is still used to access the memory afterwards, and expected data
    could be found in there, or not - in the meantime some other part of the
    program could have allocated piece(s) of the free'd memory.
  - The way to detect/prevent this is to set the pointer to `NULL` after freeing
    it.
- Double free: free already free'd buffer
  - Can corrupt internal heap allocator structures if it does not track the
    state of memory chunks
  - Use static/dynamic analysis and/or heap allocator with the ability to detect
    this

#source use-after-free.c

## Memory leaks

If memory allocated on the heap is not freed, it creates a resource leak called
a *memory leak* as the allocator deems such memory used even that your code no
longer uses it.

Depending on its size(s) this might cause a problem of running out of memory
later on, and then `malloc`/`calloc` can start returning a null pointer as an
indication of allocation failure(s).

The leaks can be checked using static or dynamic analyzers.

:wrench: Write a program that takes all arguments that follow `argv[0]`,
concatenates them (without the terminating `NUL` character) into one string
dynamically allocated via `malloc`() and prints this string to the standard
output.

The concatenation can be done either by hand (try that first) or
using `strncat()` (try that afterwards).

#solution argv-concat.c

You can then put the string processing in a loop and comment out the `free`()
call on the allocated memory.  Then check with `top -s 1` on Linux, macOS, or
any other Unix-like system (or use any other suitable system monitoring tool)
that the memory size of the running program quickly increases.

#source argv-concat-nofree.c
