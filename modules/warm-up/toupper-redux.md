## `toupper`

rewrite the
#module home-assignments/toupper.md convert small characters to upper case
program using a function.

#solution toupper.c

### Implementation notes

  - there is a `toupper()` library function from C99 so use a different name,
    say `mytoupper()`
    - what happens if the program defines `int toupper(int)` ?
      - the symbol in `libc` is
	[*weak*](https://en.wikipedia.org/wiki/Weak_symbol) so it works

### Variant: do this via lookup table - array

   - generate array indexed by `a`..`z` (with corresponding values `A`..`Z`) in
     `main()` and use the array in the `mytoupper()` function
   - arrays passed as function argument are in reality converted to pointers
     (to be introduced later)
     - so it is useless to write their size like this:

```C
	/* see what is the value of sizeof(array) inside the func() */
         void func(int array[3]);
```

- this is better:

```C
         void func(int array[], size_t size);
```

  - also, if the items in the array are changed in the function, they will be
    changed in the array itself (consequence of pointer conversion)

  - what happens if `mytoupper(-1)` ?
  - `short` is sufficient to store the value:

```C
    short uppper[] = { 'A', 'B', ... };
```

#solution toupper-table.c
