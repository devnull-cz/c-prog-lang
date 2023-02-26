## :wrench: Count digit occurrence

If unsure about the behavior, compile our solution and run it.

- Read characters until `EOF` and count occurence of each 0-9 digit.  Only use
  what we have learned so far.  You may end up with longer code than otherwise
  necessary but that is OK.

```
$ cat /etc/passwd | ./a.out
0: 27
1: 37
2: 152
3: 38
4: 39
5: 43
6: 34
7: 35
8: 29
9: 31
```

#solution count-numbers.c

- Variant: instead of printing occurrences, print `*` characters to get a
  histogram.  Use `log()` (see `math(3)`) to trim the values down.
