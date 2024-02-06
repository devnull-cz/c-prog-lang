# Comments

- `/* one line comment */`

- multi line comment:
```
  /*
   * multi line comment.  Follow the C style.
   * multi line comment.  Follow the C style.
   */
```
- `// one line comment from C99+`

- use comments sparingly
  - not very useful:
  ```C
  /* increment i */
  ++i;
  ```
  - produce meaningful comments, not like this:
  ```C
  /* probably makes sense, but maybe not */
  if (...)
           do_something()
  ```

- Pick a reasonble style and stick to it.  Mixing one line comments using both
  `//` and `/* */` is not the best style.

- In general, you can always figure out what the code does, it is just a matter
  of time to get there, but it may be impossible to figure out why the code
  works that way.  The reason might be historical, related to some other
  decisions or existing code, purely random, or something else.  If not clear,
  commenting code on the **why** is extremely important.
