## Animals: maximum number of legs

Implement:

```C
struct animal *maxlegs(struct animal *, size_t len);
```

It will use the `getlegs()` function and will return an animal with highest leg
count. Return pointer to the structure (= array element) from the function.

The `main()` function (in separate file) will define an array of animals and
will call `maxlegs()`.  The name of the animal with maximum number of legs will
be printed to standard output.

Note: does the original structure change if the structure returned from the
function was modified within the function?  How to fix this ?

Solutions:
  - #solution animal\_maxlegs.c
  - #solution maxlegs.c
  - #solution animals.h
  - #solution animal.h
