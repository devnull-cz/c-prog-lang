## Debug prints

- the most primitive debugging technique is to insert debug prints
- `fprintf()`
  - do not use `printf()` for debugging unless you know what you are doing
    (stdout is cached in `libc`)
  - use a unique text for each debug text, for example:

```C
/* some code */
fprintf(stderr, "DBG 1\n");
/* some code */
fprintf(stderr, "DBG 2\n"); ...
/* some code */
fprintf(stderr, "DBG 3\n"); ...
...
```

- if you need to put another debug message in between 1 and 2, "1.5" seems like
  an easy way to do it.
