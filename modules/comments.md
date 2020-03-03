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
