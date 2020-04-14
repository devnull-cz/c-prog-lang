# Changing pointers

- in order to change the value of a pointer in a function, it has to be passed
  as a pointer to a pointer
  - this makes sense, because the storage address of a plain pointer is not
    known to the function, and therefore we must pass in its address so that we
    can change the object the address points to by dereferencing the address.

#source ptr-change.c
