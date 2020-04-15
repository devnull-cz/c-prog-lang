# Flexible array member

- since C99 (§6.7.2.1, item 16, page 103)
- it is an array without a dimension specified that is the last member of the
  structure
  - this is handy for structures with a fixed header and "padding" data of
    flexible length that is allocated dynamically
  - why not to use a pointer instead ? this is good when passing data over
    boundaries such as network, kernel/userland, etc. since no deep
    structure copy is required
    - just copy the structure as whole (it is just necessary to know how
      large it is) because it is all contiguous memory

- e.g.:
```C
struct item {
	int value;
	// possible other members
	char payload[];
	// nothing can follow
};
```

- `sizeof (struct item)` will give the size without the last member computed

```
+-------------+-----------------------+
| struct item |      payload ...      |
+-------------+-----------------------+
```

- previously, this was hacked around using array with 0 members and GCC accepted
  this. Since C99 this can be done properly using this technique.
- the data is allocated like so:

```C
struct item *p = malloc(sizeof (struct item) + payload_len * sizeof (p->payload[0]));
```

- with this approach the overall structure alignment might be lost
  - i.e. it is necessary to set the payload length according to the size
    of the structure if you want to maintain alignment

code: #source flexible-array-member.c
