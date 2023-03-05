# Negative numbers

Negative numbers are usually stored in [two's complement](https://en.wikipedia.org/wiki/Two's_complement)
(however, that is implementation defined by C99).

In short, you take an absolute value, create one's complement (inverting the
digits in binary representation) and add 1.  There are several advantages of
this representation, one is that there is only 1 zero (not negative and positive
zero if we used the highest bit to track the sign).  That is why a `signed
char`, for example, can hold -128 to 127, and not just -127 to 127.

For a `char`:
```
 10000000	-128
 ........
 11111101	  -3
 11111110	  -2      ^
 11111111	  -1      |
 --------------------------
 00000000	   0      |
 00000001	   1      v
 00000010	   2
 ........
 01111111	 127
```

On Unix systems the shell reports the -1 return value as 255 in `echo $?`.  Even
though the `main()` returns integer (4 bytes), the calling program (shell) gets
just the low 8 bits and interprets them as unsigned quantity.

#source return-1.c
