# :wrench: Linked list

Declare a structure that forms a simple linked list and holds an integer as a
value.  The program is executed with a single argument specifying how many items
the list will have.

Allocate a new structure and insert values into the head (global variable).
Each new list item will have its value incremented by one.

Aside from the value itself, each node needs to hold a pointer to the next
structure in the list.  The last node has the next pointer set as `NULL`.

Once the list is completed, print its value by traversing its items from the
head to its end.

```
$ ./a.out
a.out: usage: ./a.out <num>
$ ./a.out 10
9
8
7
6
5
4
3
2
1
0
```

#solution linked-list-free.c

After the list is printed, free it. Make sure there are no memory leaks.
