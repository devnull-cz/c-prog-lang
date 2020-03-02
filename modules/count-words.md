Print out number of words read from the standard input.  Ideally, use your
`getchar`() based code from your repository to start with.

**Always try to reuse code you have already written!**

A *word* is defined as group of any characters surrounded by whitespace
characters.  For our case these will suffice: a tabelator, a space, and a
newline.

- write your own check for a whitespace character, do not use library functions
  for that

- check correctness of your implementation with `wc -w <file>`

- what happens if the number of words exceeds the type that stores the count?

:eyes: [words.c](/src/words.c), it actually uses a library check for white
space for simplicity

:eyes: another solution is [words2.c](/src/words2.c).  It is even simpler than
the first solution while not using the library function.

Example:

```
$ cat /etc/passwd | ./a.out
70
```
