# The `sizeof` operator

- The `sizeof` operator computes the byte size of its argument which is either
  an expression or a type name
  - This is not a function so you can use it without parens: `sizeof foo` unless
    its argument is a type name, in that case parens are required.  However, for
    better readability parenthesis are usually used.

```C
sizeof (1);	// OK
sizeof 1;	// OK but "sizeof (1)" is better.
sizeof 1 + 1;	// See?
sizeof (int);	// OK
sizeof int;	// Syntax error.
```

  - Its type is `size_t` which is an unsigned integer according to the
    standard.  However, the implementation (= compiler) can choose whether
    it is an `unsigned int`, an `unsigned long int`, or an `unsigned long long
    int`.
  - In printf(), the `z` modifier modifies `u` to `size_t`, so this is the
    right way to do it:

```C
printf("%zu\n", sizeof (13));
// --> 4
```

  - you may see code using `%u`, `%lu`, `%llu` for `sizeof` values.  However,
    that will only work based on a specific compiler and the architecture and
    may not work using a different combination.  Always use `%zu` for arguments
    of type `size_t`.

- the expression within the `sizeof` operator is **never** *evaluated* (the
  compiler should warn you about such code).  **Only the size in bytes needed to
  store the value if evaluated is returned.**

```C
int i = 1;
printf("%zu\n", sizeof (i = i + 1));
// --> 4
printf("%d\n", i);
// --> 1
```

- :wrench: Try `sizeof` on various values and types in printf(), compile with
  `-m 32` and `-m 64` and see the difference

```C
sizeof (1);
sizeof (char);
sizeof (long);
sizeof (long long);
sizeof ('A');
sizeof ('\075');
sizeof (1LL);
// ...
```

- We will get there later in semester but if you are bored, try to figure out
  why the following is going to print `1 4 4`:

```C
char c;
printf("%zu\n", sizeof (c));
// --> 1
printf("%zu\n", sizeof (c + 1));
// --> 4
printf("%zu\n", sizeof (+c));
// --> 4
```

The `sizeof` operator is usually evaluated during compilation time however
this is not universally true.  For Variable Length Arrays (VLAs) it has to
happen during runtime.  The VLAs will be explained later.
