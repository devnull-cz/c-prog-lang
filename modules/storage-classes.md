# Storage classes

- there are two storage classes - *automatic* and *static*
- the storage class determines the lifetime of the storage associated with the
  identified object
- declaration within a block creates an automatic object.  Its storage is valid
  only within the very same block.
- only one storage class specifier may be given in a declaration
- objects declared outside of any block is always of the static storage class
  (e.g. global variables).
- static local objects (e.g. `static int i;`) retain their value upon reentry to
  functions and blocks.
- you can initialize a static object.  The initialization happens just once.

#source fn-static-object.c

This one also shows how to use `goto`.  More on that later.

#source block-static-object.c

Local variables are implicitly automatic but you could use the `auto` keyword
(noone does that though):

```C
int
main(void)
{
	auto int i;
}
```

You can also verify that as mentioned above, global variables can be only in the
static storage class:

```C
$ cat main.c
auto int j;

int main(void)
{
}
$ cc main.c
main.c:1:10: error: illegal storage class on file-scoped variable
auto int j;
         ^
1 error generated.
```
