# Linked list

Declare a structure that will form a simple linked list and will hold an integer
as a value.  The program will be run with a single argument specifying how many
items the list will have.

Allocate a new structure and insert into the head (global variable).  Each new
item will have its value incremented by one.

Aside from the value itself, each node needs to hold a pointer to the next
structure in the list.  The last node has the next pointer set as NULL.

Once the list is complete, print its value by traversing its items from head to
end.

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

:key: code: #source linked-list-free.c
