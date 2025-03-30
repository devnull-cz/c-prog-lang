# Comments

- `/* One line comment */`

- Multiline comment:
```
  /*
   * Multiline comment.  Follow the C style.
   * Multiline comment.  Follow the C style.
   */
```
- `// One line comment from C99+`

- Use comments sparingly.  Not useful:

```C
/* Increment i */
++i;

/* Printing assertion */
print_assertion();
```

- Produce meaningful comments, not like this:

```C
/* Probably makes sense, but maybe not */
if (...)
	do_something()
```

- Pick a reasonble style and stick to it.  Mixing one line comments using both
  `//` and `/* */` is not the best style.

- Including another `/*` comment sequence within a `/*` comment is allowed but
  it does not introduce another comment.  A comment contents is only examined to
  find the terminating `*/` sequence.  C99, 6.4.9 Comments, paragraph 1.

- Likely not much useful but the following is a valid comment as well.

```C
//\
this is a comment \
and this is still part of it
```

- In general, you can always figure out what the code does, it is just a matter
  of time to get there, but it may be impossible to figure out why the code
  works that way.  The reason might be historical, related to some other
  decisions or existing code, purely random, or something else.  If not clear,
  commenting code on the **why** is extremely important.  See also [Chesterton's
  fence principle](https://en.wikipedia.org/wiki/G._K._Chesterton).
