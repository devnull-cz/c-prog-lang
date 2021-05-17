# Storage classes

- two classes - *automatic* and *static*
- declaration within a block creates an automatic object.  Its storage is valid
  only within the very same block.
- the storage class determines the lifetime of the storage associated with the
  identified object
- only one storage class specifier may be given in a declaration
- objects declared outside of any block is always of the static storage class
  (e.g. global variables).
- static objects retain their value upon reentry to functions and blocks.
- you can initialize a static object.  The initialization happens just once.

#source fn-static-object.c

This one also shows how to use `goto`.  More on that later.

#source block-static-object.c

Local variables are implicitly local but you could use the `auto` keyword (noone
does that though):

```C
int
main(void)
{
	auto int i;
}
```

You can also verify that as mentioned above, global variables always in the
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
