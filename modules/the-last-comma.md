# The last initializer and a comma

In C89, having a comma after the last initializer was a syntax error.  Since
C99, it is allowed and optional.

```C
struct s {
	int a;
	int b;
} s = { 1, 2, };	// ',' after 2 is optional
```

See why keeping the last comma always there might be a very good idea:

#source missing-comma-in-initializer.c
