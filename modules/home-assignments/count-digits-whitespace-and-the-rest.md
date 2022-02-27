## :wrench: Count digits, white space characters, and the rest

Print total number of (decimal) numbers, white space (tab, space, newline) and
anything else from the input.  **I.e. the program prints out three numbers.**

Obviously, reuse code you wrote for digit occurence counting:
#module count-digit-occurence.md

- write the program using direct comparisons like this:

```C
c >= '0' && c <= '9'
c == ' ' || c == '\t' || c == '\n'
```

- put both the checks into separate functions
- then write a new version of the program and use:
  - `isspace`() from C99
  - `isdigit`() vs `isnumber`() - the latter detects digits + possibly
	  more characters (depending on locale setting)
