## `getbits`()

Implement a function `getbits(x,p,n)` that returns the (right adjusted) `n`-bit
field of `x` that begins at position `p`.  We assume that bit position `0` is at
the right end and that `n` and `p` are sensible positive values.  For example,
`getbits(x,4,3)` returns the three bits in positions 4, 3 and 2, right-adjusted.

The idea is to zero out anything that is to the left of `p`, then shift those
`n` bits to the very right, and you get the result.

```C
/* 1 0000 0000: should return 1 */
i = getbits(0x100, 8, 1);
(void) printf("0x%X\n", i);
assert(i == 1);

/* 1110 0100: should return 9 (1001 in binary) */
i = getbits(0xe4, 5, 4);
(void) printf("0x%X\n", i);
assert(i == 9);

/* 1010 1010: should return the same number, ie. 0xAA */
i = getbits(0xAA, 7, 8);
(void) printf("0x%X\n", i);
assert(i == 0xAA);
```
