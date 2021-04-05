# Warm-up

:wrench: task:

  - extend the program #source tr-d-chars.c
  from last time to translate character input, e.g.
```
tail /etc/passwd | tr 'abcdefgh' '123#'
```
  - use character arrays defined with string literals to represent the 2 strings
    - see the tr(1) man page on what needs to happen if the 1st string is longer
      than the 2nd
      - do not store the expanded 2nd string as literal in your program !

  code: #source tr.c

:wrench: task (bonus): refactor the code into a function(s)

- remember that arrays are passed into a function as a pointer (to be explained
  soon, not needed now) which can be used inside the function with an array
  subscript.
