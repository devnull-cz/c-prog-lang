# Integer overflow

What happens if an `int` overflows?

- The behavior of an integer overflow depends on whether the type is
  signed or unsigned.
	- :heavy\_exclamation\_mark: For signed types the behavior is
#module undefined-behavior.md undefined.
	I.e. you cannot rely that an overflow of a positive quantity in
	any signed integer will be turned into a negative number.
- Some compilers will allow to choose the behavior of signed overflows
  using special options (`-fwrapv` for GCC), though.
- For unsigned integers, the spec requires that overflow always wraps around
  (modulo power of 2).
	- #source int-overflow.c
	- #source unsigned-overflow.c
- Use `-fstrict-overflow -Wstrict-overflow` (will become active only for higher
  optimization levels, i.e. `-O<X>` where `X > 1`) to stay on the safe side.

See the difference in using `-ftrapv` and not:

```C
int
main(void)
{
	int i = 2147483647;
	printf("%d\n", ++i);
}
```

```
$ gcc main.c
$ ./a.out
-2147483648
$ gcc -ftrapv main.c
$ ./a.out
Aborted (core dumped)
```
