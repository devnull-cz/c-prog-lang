# Flexible array member

- since C99 (§6.7.2.1, item 16, page 103)
- it is an array without a dimension specified as the **last member** of the
  structure
  - handy for structures with a fixed header and some "padding" data of flexible
    length that is allocated dynamically
  - why not to use a pointer instead?  It is good when passing data over
    boundaries such as network, kernel/userland, etc. since no structure
    copy is required.
    - just copy the structure as a whole (however, it is necessary to know how
      large is the padding) because it is all contiguous memory
- `sizeof (the_structure)` gives you the size of the structure **as if
  the flexible array was empty**.

Example:

```C
struct item {
	int value;
	// possible other members
	char payload[];
	// nothing can follow
};
```

`sizeof (struct item)` will give the size **without the last member computed**

```
+-------------+-----------------------+
| struct item |      payload ...      |
+-------------+-----------------------+
```

Previously, this was hacked around using array with 0 members and GCC accepted
this.  Since C99 this can be done properly using this technique.

The extra data is allocated as follows:

```C
struct item *p = malloc(sizeof (struct item) + payload_len * sizeof (p->payload[0]));
```

- with this approach the overall structure alignment might be lost
  - i.e. it is necessary to set the payload length according to the size
    of the structure if you want to maintain the alignment

#source flexible-array-member.c