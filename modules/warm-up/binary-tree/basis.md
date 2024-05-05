## Binary tree

- Define a structure for a binary tree using the `structure node_s` name.
- Each node of the tree can store either an `int` or a string (`char[]` of
  some fixed size).
- There is a member `t` of an `int` type.  That determines the data type stored
  in the node, e.g. `0` for `int`, `1` for `char[]`.
- Build a tree using a bunch of nodes (can be totally unbalanced).
	- Can be statically initialized using local variables (or generated
	  randomly however this will probably take more time to do and might
	  require allocation on the heap).
- Implement a function to perform the depth-first traversal that accepts a
  pointer to its root node and prints all data stored in the tree represented
  by the node based on the type of data in each node.
