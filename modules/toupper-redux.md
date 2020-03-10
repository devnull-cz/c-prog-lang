## toupper

rewrite the "convert small characters to upper case" program from last time using:
  1. function
  1. function using ternary operator (single line of code)

### implementation notes

  - there is a `toupper()` library function from C99 so use `mytoupper()`

  - variant: do this via lookup table - array
     - arrays passed as function argument are in reality converted to pointers
       (to be introduced later)
       - so it is useless to write their size like this:
```C
         void func(int array[3]);
```
- this is better:
```C
         void func(int array[], size_t size);
```
  - also, if the items in the array are changed in the function,
         they will be changed in the array itself (consequence of pointer
         conversion)

  - what happens if `conv_to_upper(-1)` ?
  - `short` is sufficient to store the value:
```C
    short uppper[] = { 'A', 'B', ... };
```

solution: [toupper.c](src/toupper.c)


