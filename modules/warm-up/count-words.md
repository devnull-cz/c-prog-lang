## Count words

Print out number of words read from the standard input.  Ideally, use your
`getchar` based code from your repository to start with.

**Always try to reuse code you have already written!**  Then do not forget to
upload it to your
#module scm.md source code management repository.

A *word* is defined as a group of any characters surrounded by whitespace
characters.  Those are: a tabelator, a space, and a newline.

- Write your own check for a whitespace character, do not use library functions
  for that.

- Check correctness of your implementation with `wc -w <file>`

- What happens if the number of words exceeds the type that stores the count?

#solution words.c
Does uses a library check `isspace` for white space for simplicity.

#solution words2.c
It is even simpler than the first solution while not using the library function.

Example:

```
$ cat /etc/passwd | ./a.out
70
```
