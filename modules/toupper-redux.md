## toupper

rewrite the [convert small characters to upper case](/modules/toupper.md)
program from last time using a function.

### implementation notes

  - there is a `toupper()` library function from C99 so use `mytoupper()`
    - what happens if the program defines `int toupper(int)` ? (the symbol in `libc` is *weak* so it works)
  - variant: do this via lookup table - array
     - arrays passed as function argument are in reality converted to pointers
       (to be introduced later)
       - so it is useless to write their size like this:
```C
         void func(int array[3]); // see what is the value of sizeof(array) inside the func()
```
- this is better:
```C
         void func(int array[], size_t size);
```
  - also, if the items in the array are changed in the function,
         they will be changed in the array itself (consequence of pointer
         conversion)

  - what happens if `mytoupper(-1)` ?
  - `short` is sufficient to store the value:
```C
    short uppper[] = { 'A', 'B', ... };
```

solution: [toupper.c](/src/toupper.c)
