## Print binary representation of positive number

:wrench: Task

Print `argv[1]` in binary (assume it is a correct positive decimal number
that will fit `unsigned int`) to standard output.
Note that `printf`(3) does not have a conversion specifier for it (unlike 'x'
for hexa and 'o' for octal).  Limit the input to positive `int`s.
Do not use bit operators even if you know how to (ie. do NOT use `>>` etc.)

To verify, use bc(1) with `obase=2`.  E.g.:

```
$ bc
obase=2
10
1010
255
11111111
2^31-1
1111111111111111111111111111111

$ ./a.out 2147483647
1111111111111111111111111111111
$ ./a.out 255
11111111
$ ./a.out 348508345
10100110001011101000010111001
```

You can also use `obase=8`, `obase=16`, etc.  Note that bc(1) takes only capital
letters as digits, ie. use "E4" for 0xe4, not "e4".  "e4" is treated as a
variable:

```
$ bc
ibase=16
obase=2
e4
0
E4
11100100
```

#solution print-in-binary.c


