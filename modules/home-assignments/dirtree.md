## Create and traverse path tree

In memory, build a tree of paths, where each node is a path element. The tree
starts with root '/', the non-leaf nodes are directories, the leaves are files.
The three can look e.g. like this:

```
	 "/"
       /  |   \
      /   |     \
  "foo/" "f.txt"  "bar/"
  /   \
"a.c" "b.c"
```

Populate the tree with given paths and print the leaves (no particular order),
one per line.  Then free the allocated memory.

Each node can have constant number of children.

Possible input:
```C
	char *paths[] = { "/beverages/coffee/espresso.java",
			"/beverages/alcohol/beer.c",
			"/food/healthy/vegetarian/salad.txt",
			"/food/healthy/fruit/blueberries.hs",
			"/food/unhealthy/cake.md" };
```

#solution dirtree.c

bonus tasks:
  - print also non-leaf nodes via depth first, with each node indented based on
    its tree depth.  E.g:

```
    $ ./a.out
    /
    	foo/
		a.c
		b.c
	f.txt
	bar/
```

  - remove the limitation for the constant number of children
  - print full paths of all files in the tree (hint: backpointers)
