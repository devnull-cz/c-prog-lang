# The `sizeof` operator

- the `sizeof` operator computes the byte size of its argument which is an
  expression or a type
  - its type is `size_t` which is an unsigned integer according to the
    standard.  However, the implementation (= compiler) can choose whether
    it's an `unsigned int`, an `unsigned long int`, or an `unsigned long long
    int`.
  - in printf(), the `z` modifier modifies `u` to `size_t`, so this is the
    right way to do it:
```C
	printf("%zu\n", sizeof (13));
	// --> 4
```

- the expression within the `sizeof` operator is **never** executed (the
  compiler should warn you about such code).

```C
	int i = 1;
	printf("%zu\n", sizeof (i = i + 1));
	// --> 4
	printf("%d\n", i);
	// --> 1
```

- :wrench: try `sizeof` on various values and types in printf(), compile with
  `-m 32` and `-m 64` and see the difference
```C
	sizeof (1);
	sizeof (char);
	sizeof (long);
	sizeof (long long);
	sizeof ('A');
	sizeof (1LL);
	// ...
```
- we will get there later in semester but if you are bored, try to figure out
  why the following is gonna print `1 4 4`:
```C
	char c;
	printf("%zu\n", sizeof (c));
	// --> 1
	printf("%zu\n", sizeof (c + 1));
	// --> 4
	printf("%zu\n", sizeof (+c));
	// --> 4
```

