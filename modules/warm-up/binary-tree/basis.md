## Binary tree

- define a structure for a binary tree using `structure node_s`
- each node of the tree can store either `int` or string (`char[]` of arbitrary
  size)
- there will be `int` member `type` that will signify the data stored in the
  node, e.g. 0 for `int`, 1 for the `char[]`
- define a tree using bunch of nodes (can be totally unbalanced)
  - can be statically initialized (or generated randomly however this will
    probably take more time to do and might require allocation on heap)
- implement a function to perform depth-first traversal that will accept pointer
  to a node and will print the data stored in the node based on the type
