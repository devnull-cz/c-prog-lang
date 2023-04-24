## :wrench: binary tree from binary representation

Write a program that creates a binary tree with N + 1 nodes, where N
is specified as command line argument.

Each node, besides root (that will be created always), will contain an integer
and will be created like this: take a binary representation
of the number in sequence {0, 1, ..., N - 1} and traverse the pre-existing
tree using this representation until a NULL node pointer is found.
0 means left child, 1 means right child.

For example for 5 (101 in binary), the tree will be created as follows:
  1. create root node
  1. create right node, descend
  1. create left node, descend
  1. create right node, descend, put the number in

Once the tree is populated, traverse the tree (whatever method works)
count the nodes and print the number to standard output.

Variant: add a function pointer to each node that will be called on visit.
The number stored in the node will be the sole argument of this function
Use that to traverse the tree.
