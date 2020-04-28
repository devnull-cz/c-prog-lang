# The last initializer and a comma

In C89, having a comma after the last initializer was a syntax error.  Since
C99, it's optional.

```C
struct s {
	int a;
	int b;
} s = { 1, 2, };	// ',' after 2 is optional
```
