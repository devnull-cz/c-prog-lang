# Negative numbers

Negative numbers are usually stored in [two's complement](https://en.wikipedia.org/wiki/Two's_complement)
(however, that is implementation defined by the standard).

In short, you take an absolute value, create one's complement
(inverting the digits in binary representation) and add 1.  There
are several advantages of this representation, one is that there is only 1 zero 
(not negative and positive zero if we used the highest bit to track the sign).  
That is why a `signed char`, for example, can hold -128 to 127,
and not just -127 to 127.

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
though the `main()` returns integer (4 bytes), the shell takes just low 8 bits
and interprets them as unsigned quantity.

#source return-1.c

If `long` is 8 bytes, and `int` 4 bytes, then `-1L < 1U` is true as you might
expect.

However, `-1 > 1U` is true because -1 is promoted to unsigned.  Two's complement
representation of -1 is (see the paragraph above):
```
(1) take absolute value of 1	00000000.00000000.00000000.00000001
(2) one's complement		11111111.11111111.11111111.11111110
(3) add 1 to get 2's complement	11111111.11111111.11111111.11111111
```
which is `2^32 - 1` when interpreted as unsigned quantity.

Just `printf("%u\n", -1)` to see it will print `4294967295` (use the Unix/Linux
`bc` command and type `2^32-1` to verify).

#source signed-plus-unsigned.c
#source signed-to-unsigned.c

The assymetry of the negative/positive interval can lead to the program crashing
on architectures that detect it. This is consequence of hardware handling rather
than the language.

#source crashme.c

- run with `-INT_MIN` (see `limits.h`) and `-1`.  `INT_MIN` is usually
  `-2147483648`. The program would normally yield `2147483648` (positive number)
  however that would be `INT_MAX + 1`.
- works in 64-bit mode as well due to int being passed in 32-bit registers

```
	$ cc -m64 crashme.c
	$ ./a.out 2147483648 -1
	-2147483648 -1
	Floating point exception: 8
	$ echo $?
	136
	$ kill -l 136
	FPE

	$ cc -m32 crashme.c
	$ ./a.out 2147483648 -1
	2147483647 -1
	$
```

## :wrench: Quiz 1

- what is the result if `0xff` `signed char` and `0xff` `unsigned char` are
  compared using the `==` operator ?
  - write down the hexadecimal representation of the integers corresponding to
    the 2 chars with `printf()`

#solution int-promotion.c

- note that if the `b` character was defined as `char b` the result might be 1
  because it is up to the compiler to choose whether char will be signed
  or unsigned.  Usually it is signed though. There are compiler options to
  specify this, e.g. GCC has `-funsigned-char` and `-fsigned-char`

## :wrench: Quiz 2

Will the program print the whole array ?
  - try to come up with reason of the expected behavior before running the
    program.

#source whole-array.c
